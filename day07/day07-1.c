#include <stdio.h>

int main() {

	int n;
	
	do {
		// 피라미드 층 수 입력
		printf("층을 입력하세요 : ");
		scanf_s("%d", &n);

		if (n < 1) printf("층 수는 1보다 작을 수 없습니다.\n");
	} while (n < 1);  // 입력한 층 수가 1 미만일 때, 층 수 다시 입력


	printf("%d층 피라미드\n", n); // 피라미드 층 수 표시

	for (int i = 1; i <= n; i++) { // 각 층 마다 별을 찍기 위한 반복

		// 공백 출력
		for (int j = i; j < n; j++) { // 공백의 개수는 n-i (i는 층..ex: 1층 -> n-1, 2층 -> n-2 .... n층 -> n-n = 0 
			printf(" ");
		}

		// '*' 출력
		for (int j = 1; j <= (2 * i - 1); j++) { // 각 층별 별 개수는 2 * (해당 층 번호) - 1
			printf("*");
		}

		printf("\n");

	}


	return 0;
}