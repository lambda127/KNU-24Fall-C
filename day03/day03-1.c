#include <stdio.h>

int check_prime(int num) {
	int cnt = 0;

	for (int i = 2; i < num;i++) {
		if (num%i==0) {
			cnt++;
		}
	}

	if (cnt == 0) {
		return 1;
	}

	return 0;
}

int main() {
	int num;

	printf("�Ҽ����� Ȯ���� ���� �Է��ϼ��� : ");
	scanf_s("%d", &num);

	if (check_prime(num) == 1) {
		printf("�ش� ���� �Ҽ��Դϴ�.\n");
	}
	else {
		printf("�ش� ���� �Ҽ��� �ƴմϴ�.\n");
	}

	
	return 0;
}