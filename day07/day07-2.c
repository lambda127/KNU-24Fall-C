
// Monte Carlo Algorithm

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define BILLION 1000000000  // 10�� ��� ����

int main() {

	double x = 0;	// ���� ���� x��ǥ
	double y = 0;	// ���� ���� y��ǥ
	double pi = 0;	// ���� �� ��� �� ����
	

	int count = 1, circle = 0;	// count -> ���� Ƚ�� ����, circle -> �� �ȿ� �� ���� ���� ����
	int rate = 0;				// ����� ����

	srand(time(NULL));

	while (count <= BILLION) { // 10��� ����

		x = (double)rand() / (double)RAND_MAX;	// x �� ���� ����
		y = (double)rand() / (double)RAND_MAX;	// y �� ���� ����

		if (sqrt(pow(x, 2) + pow(y, 2)) <= 1) circle++;	// ���� ���� (������ 1) ���� ���� �� circle 1 ����

		if (count % (BILLION/100) == 0) {	// BILLION/100 -> 1000�� ���� ������ ��������... => 1000���� ���� ����
			rate = count / (BILLION / 100);	// �����

			pi = 4 * ((double)circle / (double)count);	// Monte Carlo Algorithm -> 4 * (�� �ȿ� �� ���� ����) / (���� ���� ����)

			printf("%d%%����.. ������ : %lf ", rate, pi);	// �����, ���� ���� �� ���

			for (int i = 0; i < 20; i++) {	// �� 20ĭ���� ���൵ ǥ�� -> �� ĭ�� 5% ����

				if (i < (rate / 5)) {	// ������� 5�� ������ �ִ� 20ĭ ���� ����
					printf("��"); // i�� ���ǿ� �����ϴ� ��� -> �������� 5�� ������ �� 1, 2, 3,...20�� �Ǵµ� i�� ���� �� ������ ���� ��� '��' ��� 
				}
				else {
					printf("��"); // �ƴϸ� '��'
				}

			}
			printf("\n");
		}
		count++; // ���� Ƚ�� ����
	}
	printf("������ ; %lf\n", pi);	// ���� ��� ���


	return 0;
}