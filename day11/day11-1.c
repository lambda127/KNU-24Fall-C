#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>


int main() {

	int a = 0, b = 0, c = 0;
	int sol1 = 0, sol2 = 0;
	int check_expr = 0;

	printf("���������� a*x^2 + b*x + c = 0�� ��� a, b, c�� �Է��ϼ���.\n: ");
	scanf_s("%d, %d, %d", &a, &b, &c);

	check_expr = pow(b, 2) - (4 * a * c);

	sol1 = check_expr < 0 ? 0 : ((-1 * b) + sqrt(check_expr)) / (2 * a);
	sol2 = check_expr < 0 ? 0 : ((-1 * b) - sqrt(check_expr)) / (2 * a);

	if (check_expr < 0) {
		printf("���������� %d*x^2 + %d*x + %d�� ���� ��� �Դϴ�.\n", a, b, c);
	}
	else if (check_expr == 0) {
		printf("���������� %d*x^2 + %d*x + %d�� ���� %d(�߱�)�Դϴ�.\n", a, b, c, sol1);
	}
	else {
		printf("���������� %d*x^2 + %d*x + %d�� ���� %d�� %d�Դϴ�.\n", a, b, c, sol1, sol2);
	}

	return 0;
}