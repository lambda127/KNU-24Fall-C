#include <stdio.h>

int main() {

	int n;

	printf("층을 입력하세요 : ");
	scanf_s("%d", &n);

	if (n >= 1) {
		
		printf("%d층 피라미드\n", n);

		for (int i = 1; i <= n; i++) {

			for (int j = i; j < n; j++) {
				printf(" ");
			}
			
			for (int j = 1; j <= (2 * i - 1); j++) {
				printf("*");
			}

			printf("\n");

		}

	}


	return 0;
}