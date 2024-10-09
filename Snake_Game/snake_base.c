/*
*만들 거
-----------------------------------------------------------------------------------------------

1. 자신 몸통 닿을 시 게임오버 - 완

2. 선물 상자  다음 효과 중 하나를 랜덤으로 적용  -> event  - 완
	속도 변화(logic()안의 sleep(speed) 조절  - 완
		-> 전역변수 speed를 작게 하면 할 수록 빠른 속도로 진행/크게하면 느린 속도로 진행
		0 -> 속도 증가 - 완
		1 -> 속도 감소 - 완
	
	2 -> 특정 점수 범위 안에서 랜덤으로 점수 증가 (몸통길이 변화 X) - 완

	3 -> 특정 점수 범위 안에서 랜덤으로 점수 감소 - 완

	4 -> 몸통 길이 증가 (점수 증가 X) - 완
		
3. 닿으면 죽는 폭탄  -> bomb  - 완
	-> 닿는 거 감지, 닿으면 게임오버

4. 기록저장 -> fscanf_s와 fprintf를 이용, 최고 기록 읽고 화면에 띄우기, 최고기록 저장

5. 속도 변화 아이템 -> 2.의 선물 상자에서 속도 변화 효과를 별개의 아이템으로 제작 

6. 속도가 빨라지면 빠라질 수록 snake를 조종하는 것이 힘듦
	-> 게임 시작 전, 난이도 선택을 통해 처음 시작 속도를 고르게 하는 것
	-> 최고 기록 저장 시에도 난이도 별로 최고 기록을 따로 저장하는 것도 방법일 듯 함
		난이도 별 최고 기록을 난이도 선택 시에 보여 주는 것도 아주 좋을 것이라고 생각함

------------------------------------------------------------------------------------------------
*/

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
int eventx, eventy, bombx, bomby;  // event -> '?', bomb -> ▣
int event_bool = 0, bomb_bool = 0;// event와 bomb이 생성되어있는가확인
int body_length = 1;
int speed = 200; // easy -> 200, normal -> 100, hard -> 50 정도로 세팅하면 재밌을 듯




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




// 1 -> 0~149 사이의 값을 speed에서 뺌 -> 속도 증가
// 2 -> 0~99 사이의 값을 speed에 더함 -> 속도 감소
void rand_speed(int num) {
	if (num == 1)
		speed -= rand() % 150;
	
	if (num == 2)
		speed += rand() % 100;
}

// 1 -> 0~50 사이의 값을 score에서 뺌
// 2 -> 0~50 사이의 값을 score에 더함
void rand_score(int num) {
	if (num == 1)
		score -= rand() % 51;

	if (num == 2)
		score += rand() % 51;
}

//  1~5 사이 개수의 몸통 추가
void rand_body_add() {
	for (int i = 1; i <= (rand() % 5) + 1; i++) {
		insert_tail(create_body(head->x, head->y, head->direction));
		body_length++;
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

	// fruit
	fruitx = 0;
	while (fruitx == 0) {
		fruitx = rand() % 20;
	}

	fruity = 0;
	while (fruity == 0) {
		fruity = rand() % 20;
	}


	// bomb
	bombx = 0;
	bomby = 0;
	while (bombx == 0 || bomby == 0
		||(bombx == fruitx  && bomby == fruity)
		||(bombx == eventx && bomby == eventy)) {

		bombx = rand() % 20;
		bomby = rand() % 20;
	}

	

	// event
	eventx = 0;
	eventy = 0;
	while (eventx == 0 || eventy == 0
		|| (eventx == fruitx && eventy == fruity)
		|| (eventx == bombx && eventy == bomby)) {
		eventx = rand() % 20;
		eventy = rand() % 20;
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
				else if (i == bombx && j == bomby)
				{
					if (bomb_bool == 1) {
						printf("▣");
					}
					else if (rand() % 100 < 5 && bomb_bool == 0) {
						bomb_bool = 1;
						printf("▣");
					}
					else
					{
						printf(" ");
					}
				}
				else if (i == eventx && j == eventy )
				{
					if (event_bool == 1) {
						printf("?");
					}
					else if (rand() % 10 < 3 && event_bool == 0) {
						event_bool = 1;
						printf("?");
					}
					else
					{
						printf(" ");
					}
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
	printf("score = %d | body_length = %d |", score, body_length);
	printf("\n");
	printf("press X to quit the game\n");
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
		body_length++;

		score += 10;
	}


	// snake가 bomb에 닿았을 때
	if ((head->x == bombx && head->y == bomby) || (round_snake(bombx, bomby) == 1)) {
		gameover = 1;
	}


	// snake가 event에 닿았을 때
	if ((head->x == eventx && head->y == eventy) || (round_snake(eventx, eventy) == 1)) {

		// event
		eventx = 0;
		eventy = 0;
		while (eventx == 0 || eventy == 0
			|| (eventx == fruitx && eventy == fruity)
			|| (eventx == bombx && eventy == bomby)) {
			eventx = rand() % 20;
			eventy = rand() % 20;
		}

		
		int effect = rand() % 5;
		switch (effect) {
		case 0:
			rand_speed(1);
			break;

		case 1:
			rand_speed(2);
			break;

		case 2:
			rand_score(1);
			break;

		case 3:
			rand_score(2);
			break;
		case 4:
			rand_body_add();
			break;
		}
		

		event_bool = 0;

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
