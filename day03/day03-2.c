#include <stdio.h>

int factorial(int num) {
	if (num > 1) {
		return num * factorial(num - 1);
	}
	
	return 1;
}

int main() {
	int num;
	printf("°è»êÇÒ ÆÑÅä¸®¾ó°ª ÀÔ·Â : ");
	scanf_s("%d", &num);

	int result = factorial(num);
	printf("%d! = %d", num, result);
}
