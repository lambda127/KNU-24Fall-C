// C program to build the complete 
// snake game 
#include <conio.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <io.h> 
#include <Windows.h>
#include <time.h>

struct BODY 
{
	int x, y, direction; //direction : 1 -> -y, 2 -> -x, 3 -> +y, 4-> +x
	struct BODY* next;
};
typedef struct BODY body; // 타입 정의

body * head = NULL; // 머리 선언

// 연결리스트 이용으로  기존에 있던 변수 x, y 필요 없어짐에 따라 제거
int i, j, height = 22, width = 22;  
int gameover, score;
int fruitx, fruity, flag;
int speed = 200;

// 몸통 생성, 머리 혹은 앞 몸통의 좌표, 보고 있는 방향을 받아 그 다음 위치에 좌표 설정, 바라보는 방향 설정
body* create_body(int x, int y, int direction) {

	body* new_body = (body*)malloc(sizeof(body));

	switch (direction) {
	case 1:
		new_body->x = x;
		new_body->y = y - 1;
		break;
	case 2:
		new_body->x = x - 1;
		new_body->y = y;
		break;
	case 3:
		new_body->x = x;
		new_body->y = y + 1;
		break;
	case 4:
		new_body->x = x + 1;
		new_body->y = y;
		
		break;
	}
	new_body->next = NULL;
	new_body->direction = direction;

	return new_body;
}

// 마지막 몸통(꼬리) 탐색
body* find_tail() {
	body* cur = head;
	while (cur->next != NULL) {
		cur = cur->next;
	}

	return cur;
}

// 생성한 몸통을 가장 마지막에 연결
void insert_tail(body* new_body) {
	body* tail = find_tail();
	tail->next = new_body;
}

// 좌표를 받아 해당좌표에 몸통이 있는지 확인하는 함수
int round_snake(int x, int y) {
	body* cur = head->next;

	while (cur != NULL) {
		if (x == cur->x && y == cur->y) {
			return 1;
		}
		
		cur = cur->next;
	}
	
	return 0;
}

// 머리를 제외한 몸통을 움직이는 기능
// 앞 몸통의 좌표 저장(prev_x, prev_y), 자신의 좌표 임시 저장(temp_x, temp_y), 자신에게 앞 몸통 좌표 저장, 자신의 좌표 였던 좌표 prev_x, prevy애 저장
void move_body() {
	body* cur = head;
	int prev_x = cur->x;
	int prev_y = cur->y;
	int prev_direction = cur->direction;
	cur = cur->next;

	while (cur != NULL) {
		int temp_x = cur->x;
		int temp_y = cur->y;
		int temp_direction = cur->direction;

		cur->x = prev_x;
		cur->y = prev_y;
		cur->direction = prev_direction;

		prev_x = temp_x;
		prev_y = temp_y;
		prev_direction = temp_direction;

		cur = cur->next;
	}
}

// Function to generate the fruit 
// within the boundary 
void setup()
{
	gameover = 0;

	head = (body*)malloc(sizeof(body));

	// Stores height and width 
	head->x = height / 2;
	head->y = width / 2;
	head->next = NULL;
	head->direction = NULL;

	fruitx = 0;
	while (fruitx == 0) {
		fruitx = rand() % 20;
	}

	fruity = 0;
	while (fruity == 0) {
		fruity = rand() % 20;
	}

	score = 0;
}

// Function to draw the boundaries 
void draw()
{
	system("cls");
	for (i = 0; i < height; i++) {
		for (j = 0; j < width; j++) {
			if (i == 0 || i == width - 1
				|| j == 0
				|| j == height - 1) {
				printf("#");
			}
			else {
				if (i == head->x && j == head->y) {
					printf("O");
				}
				else if (round_snake(i, j) == 1) // 영역을 그리고 있는 위치에 몸통이 있는지 확인 -> 존재 O => 'o'출력
				{
					printf("o");
				}
				else if (i == fruitx && j == fruity)
				{
					printf("*");

				}
				else
				{
					printf(" ");
				}
			}
					
			
		}
		printf("\n");
	}

	// Print the score after the 
	// game ends 
	printf("score = %d", score);
	printf("\n");
	printf("press X to quit the game");
}

// Function to take the input 
void input()
{
	if (_kbhit()) {
		switch (getch()) {
		case 'a':
			flag = 1;
			break;
		case 's':
			flag = 2;
			break;
		case 'd':
			flag = 3;
			break;
		case 'w':
			flag = 4;
			break;
		case 'x':
			gameover = 1;
			break;
		}
	}
}

// Function for the logic behind 
// each movement 
void logic()
{
	Sleep(speed); // 속도 조절용 변수 (기본갑 : 200, 특정 아이템을 먹으면 빨라지게 할 예정)
	switch (flag) {
	case 1:
		// 머리의 좌표를 먼저 변경하면 머리 바로 다음 몸통이 사라지는 것을 발견 
		// -> 몸통의 좌표를 먼저 변경한 이후, 머리 좌표변경 
		// (어차피 머리가 있는 방향으로 이동 및 머리가 보고 있던 방향으로 방향값 변경)
		move_body(); 
		head->y--;
		break;
	case 2:
		move_body();
		head->x++;
		break;
	case 3:
		move_body();
		head->y++;
		break;
	case 4:
		move_body();
		head->x--;
		break;
	default:
		break;
	}

	// If the game is over 
	if (head->x < 0 || head->x > height
		|| head->y < 0 || head->y > width - 1)
		gameover = 1;

	if (round_snake(head->x, head->y) == 1) // 몸통에 머리가 닿으면 종료
		gameover = 1;

	// If snake reaches the fruit 
	// then update the score 
	if ((head->x == fruitx && head->y == fruity) || (round_snake(fruitx, fruity) == 1 )) {

		fruitx = 0;
		while (fruitx == 0 ) {
			fruitx = rand() % 20;
		}

		fruity = 0;
		while (fruity == 0) {
			fruity = rand() % 20;
		}

		insert_tail(create_body(head->x, head->y, head->direction)); // fruit을 먹었을 때 몸통 추가

		score += 10;
	}
}

void main()
{
	srand(time(NULL));

	// Generate boundary 
	setup();

	// Until the game is over 
	while (!gameover) {

		// Function Call 
		draw();
		input();
		logic();
	}


	free(head); // head 동적할당 해제
}
