#include <stdio.h>


int main() {

	int operation;
	double num1, num2;
	
	printf("���ϴ� ����� �Է��Ͻÿ�.\n1.���ϱ� 2.���� 3.���ϱ� 4.������\n");
	printf("��� : ");
	scanf_s("%d", &operation);

	printf("���� 1�� �Է��ϼ��� : ");
	scanf_s("%lf", &num1);

	printf("���� 2�� �Է��ϼ��� : ");
	scanf_s("%lf", &num2);
	
	if (operation == 1) {
		printf("%.6lf + %.6lf = %.6lf\n", num1, num2, num1 + num2);

	}else if (operation == 2) {
		printf("%.6lf - %.6lf = %.6lf\n", num1, num2, num1 - num2);

	}else if (operation == 3) {
		printf("%.6lf * %.6lf = %.6lf\n", num1, num2, num1 * num2);

	}else if (operation == 4) {

		if (num2 == 0) {
			printf("0���� ���� �� �����ϴ�.\n");
		}
		else {
			printf("%.6lf / %.6lf = %.6lf\n", num1, num2, num1 / num2);
		}
	}
	else {
		printf("�������� �ʴ� ����Դϴ�.\n");

	}

	
	return 0;
}