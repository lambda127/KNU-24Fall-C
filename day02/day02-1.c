#include <stdio.h>


int main() {

	int operation;
	double num1, num2;
	
	printf("원하는 기능을 입력하시요.\n1.더하기 2.뺴기 3.곱하기 4.나누기\n");
	printf("기능 : ");
	scanf_s("%d", &operation);

	printf("숫자 1을 입력하세요 : ");
	scanf_s("%lf", &num1);

	printf("숫자 2을 입력하세요 : ");
	scanf_s("%lf", &num2);
	
	if (operation == 1) {
		printf("%.6lf + %.6lf = %.6lf\n", num1, num2, num1 + num2);

	}else if (operation == 2) {
		printf("%.6lf - %.6lf = %.6lf\n", num1, num2, num1 - num2);

	}else if (operation == 3) {
		printf("%.6lf * %.6lf = %.6lf\n", num1, num2, num1 * num2);

	}else if (operation == 4) {

		if (num2 == 0) {
			printf("0으로 나눌 수 없습니다.\n");
		}
		else {
			printf("%.6lf / %.6lf = %.6lf\n", num1, num2, num1 / num2);
		}
	}
	else {
		printf("존재하지 않는 기능입니다.\n");

	}

	
	return 0;
}