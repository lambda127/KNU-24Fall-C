#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

// �迭�� 1~20�� ������ �� �ο�
void fillRandom(int array[SIZE][SIZE]) {
	// ���� for���� ���� ������ �迭�� ����
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			// �迭�� �� ���� �������� 1 ~ 20�� �� ����
			array[i][j] = rand() % 20 + 1;
		}
	}
}

// �迭 ���
void printArray(int array[SIZE][SIZE]) {
	printf("\n-----------------------------------\n");
	printf("�迭 ��� : \n");	

	// ���� for���� ���� ������ �迭�� ����
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			// ������ �迭�� �� ���
			printf("%2d ", array[i][j]);
		}
		printf("\n");	// ���� �� ��(10��) ��� �� �ٳ���
	}
	printf("-----------------------------------\n");
}

// �迭�� ����ŭ �̵�, ������ġ�� �迭�� ���� ���, �� �̻� �̵� �� �� ���� ��, ���� ��ġ ��� �� ���α׷� ����
void movePointer(void* array) {
	int x = 0, y = 0;				// x, y -> ��ġ
	int dist = 0, movement = 0;		// dist -> distance �̵��� �Ÿ� (���� �Ÿ�), movement -> �̵��� �Ÿ� (�迭�� ��)


	while (1) {
		movement = *((int*)array + dist);	// ���� ���࿡�� �̵��� �Ÿ� ���� (���� ��ġ�� �迭 �� ����)

		printf("���� ��ġ : (%d, %d), �迭�� �� : %d\n", x, y, movement);	// ���� ��ġ, �迭�� �� ���

		// y + �̵��� �Ÿ�	: 10 �̻��� ��� x �� ����
		//					: �ƴ� ���, y �� movement �� ��ŭ ����
		if (y + movement >= 10) {	 
			// �̵� �� x�� ���� 10 �̻��̶�� (�迭 ���� �ٱ��̶��) �� �������� �ʰ� ���� ��ġ���� ����
			if ((x + (y + movement) / 10 ) >= 10) break;

			// x �� ����, y + movement�� 20�� �� �ѱ�ٸ� +1, 20�� �Ѱ�ٸ� +2 -> �������� 10���� �������μ� �Ҽ� �Ʒ��ڸ� ���� ����
			x += (y + movement) / 10;
			// y �� ����, y + movement�� 10 �̻��̹Ƿ� 10 + n�̸� 10�� ����, 20 + n�̸� 20�� ���� �� -> �������� 10���� �������ٰ� �ٽ� 10�� ���ϹǷμ� 1�� �ڸ� �� ����
			y = y + movement - 10 * ((y + movement) / 10);
		}
		else {
			// y + movement��  10�̻��� �ƴ� ���� y �� movement�� ���� �����ش�.
			y += movement;
		}
		// movement��ŭ �̵��� �Ÿ��� �߰��Ѵ�. <- ������ �迭�� �ٷ����� �������̹Ƿ� ���ӵ� �ּҸ� �����Ƿ� �����Ϳ� distf�� �����ֹǷμ� ���� ��ġ�� �迭�� ���� ������ �� �ִ�.
		dist += movement;

	}

	printf("-----------------------------------\n");
	printf("�� �̻� �̵��� �� �����ϴ�.");
	printf("\n-----------------------------------\n");
	printf("���� ��ġ : (%d, %d), �迭�� �� : %d", x, y, movement);
	printf("\n-----------------------------------\n");
	
}

int main() {
	int array[SIZE][SIZE];

	srand(time(NULL));

	fillRandom(array);
	printArray(array);
	movePointer(array);


}