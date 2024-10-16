#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

// 배열에 1~20의 랜덤한 값 부여
void fillRandom(int array[SIZE][SIZE]) {
	// 이중 for문을 통해 이차원 배열에 접근
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			// 배열의 각 값에 랜덤으로 1 ~ 20의 값 저장
			array[i][j] = rand() % 20 + 1;
		}
	}
}

// 배열 출력
void printArray(int array[SIZE][SIZE]) {
	printf("\n-----------------------------------\n");
	printf("배열 출력 : \n");	

	// 이중 for문을 통해 이차원 배열에 접근
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			// 접근한 배열의 값 출력
			printf("%2d ", array[i][j]);
		}
		printf("\n");	// 가로 한 줄(10개) 출력 후 줄내림
	}
	printf("-----------------------------------\n");
}

// 배열의 값만큼 이동, 현재위치와 배열의 값을 출력, 더 이상 이동 할 수 없을 때, 최종 위치 출력 후 프로그램 종료
void movePointer(void* array) {
	int x = 0, y = 0;				// x, y -> 위치
	int dist = 0, movement = 0;		// dist -> distance 이동한 거리 (누적 거리), movement -> 이동할 거리 (배열의 값)


	while (1) {
		movement = *((int*)array + dist);	// 다음 시행에서 이동할 거리 저장 (현재 위치의 배열 값 저장)

		printf("현재 위치 : (%d, %d), 배열의 값 : %d\n", x, y, movement);	// 현재 위치, 배열의 값 출력

		// y + 이동할 거리	: 10 이상인 경우 x 값 증가
		//					: 아닌 경우, y 값 movement 값 만큼 증가
		if (y + movement >= 10) {	 
			// 이동 후 x의 값이 10 이상이라면 (배열 범위 바깥이라면) 더 움직이지 않고 현재 위치에서 종료
			if ((x + (y + movement) / 10 ) >= 10) break;

			// x 값 증가, y + movement가 20을 못 넘긴다면 +1, 20을 넘겼다면 +2 -> 정수형을 10으로 나눔으로서 소수 아랫자리 값을 제거
			x += (y + movement) / 10;
			// y 값 증가, y + movement이 10 이상이므로 10 + n이면 10을 빼고, 20 + n이면 20을 빼는 식 -> 정수형을 10으로 나누었다가 다시 10을 곱하므로서 1의 자리 값 제거
			y = y + movement - 10 * ((y + movement) / 10);
		}
		else {
			// y + movement가  10이상이 아닌 경우는 y 에 movement의 값을 더해준댜.
			y += movement;
		}
		// movement만큼 이동한 거리를 추가한댜. <- 이차원 배열을 다루지만 포인터이므로 연속된 주소를 가지므로 포인터에 distf를 더해주므로서 현재 위치한 배열의 값을 가져올 수 있다.
		dist += movement;

	}

	printf("-----------------------------------\n");
	printf("더 이상 이동할 수 없습니다.");
	printf("\n-----------------------------------\n");
	printf("종료 위치 : (%d, %d), 배열의 값 : %d", x, y, movement);
	printf("\n-----------------------------------\n");
	
}

int main() {
	int array[SIZE][SIZE];

	srand(time(NULL));

	fillRandom(array);
	printArray(array);
	movePointer(array);


}