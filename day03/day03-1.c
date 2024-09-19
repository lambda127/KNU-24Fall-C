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

	printf("소수인지 확인할 수를 입력하세요 : ");
	scanf_s("%d", &num);

	if (is_prime_number(num) == 1) {
		printf("해당 수는 소수입니다.\n");
	}
	else {
		printf("해당 수는 소수가 아닙니다.\n");
	}


	/*
	int  cnt = 1;

	printf("수 입력 : ");
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