#include <stdio.h>

int is_prime_number(int num) {
	//int cnt = 0;

	for (int i = 2; i < num;i++) {
		if (num%i==0) {
			return 0; //cnt++;
		}
	}

	return 1;

	/*
	if (cnt == 0) {
		return 1;
	}
	*/
}

int main() {
	int num;

	printf("�Ҽ����� Ȯ���� ���� �Է��ϼ��� : ");
	scanf_s("%d", &num);

	if (is_prime_number(num) == 1) {
		printf("�ش� ���� �Ҽ��Դϴ�.\n");
	}
	else {
		printf("�ش� ���� �Ҽ��� �ƴմϴ�.\n");
	}


	/*
	int  cnt = 1;

	printf("�� �Է� : ");
	scanf_s("%d", &num);

	for (int i = 1; i <= num; i++) {
		if (is_prime_number(i) == 1) {
			printf(" %7d", i);

			if (cnt == 10) {
				printf("\n");
				cnt = 0;
			}

			cnt++;
		}
	}
	*/

	
	return 0;
}