#include <stdio.h>

int factorial(int num) {
	if (num > 1) {
		return num * factorial(num - 1);
	}
	
	return 1;
}

int main() {
	int num;
	printf("계산할 팩토리얼값 입력 : ");
	scanf_s("%d", &num);

	int result = factorial(num);
	printf("%d! = %d", num, result);
}