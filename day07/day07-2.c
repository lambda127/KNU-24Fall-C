
// Monte Carlo Algorithm

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define BILLION 1000000000  // 10억 상수 정의

int main() {

	double x = 0;	// 찍힐 점의 x좌표
	double y = 0;	// 찍힐 점의 y좌표
	double pi = 0;	// 파이 값 계산 시 저장
	

	int count = 1, circle = 0;	// count -> 시행 횟수 저장, circle -> 원 안에 들어간 점의 개수 저장
	int rate = 0;				// 진행률 저장

	srand(time(NULL));

	while (count <= BILLION) { // 10억번 시행

		x = (double)rand() / (double)RAND_MAX;	// x 값 랜덤 생성
		y = (double)rand() / (double)RAND_MAX;	// y 값 램덤 생성

		if (sqrt(pow(x, 2) + pow(y, 2)) <= 1) circle++;	// 원의 범위 (반지름 1) 내에 들어갔을 시 circle 1 증갖

		if (count % (BILLION/100) == 0) {	// BILLION/100 -> 1000만 으로 마누어 떨어지면... => 1000만번 마다 실행
			rate = count / (BILLION / 100);	// 진행률

			pi = 4 * ((double)circle / (double)count);	// Monte Carlo Algorithm -> 4 * (원 안에 들어간 점의 개수) / (찍은 점의 개수)

			printf("%d%%진행.. 원주율 : %lf ", rate, pi);	// 진행률, 계산된 파이 값 계산

			for (int i = 0; i < 20; i++) {	// 총 20칸으로 진행도 표시 -> 한 칸당 5% 차지

				if (i < (rate / 5)) {	// 진행률을 5로 나누면 최대 20칸 차지 가능
					printf("■"); // i가 조건에 부합하는 경우 -> 진행율을 5로 나눴을 떄 1, 2, 3,...20이 되는데 i의 값이 이 값보다 작은 경우 '■' 출력 
				}
				else {
					printf("□"); // 아니면 '□'
				}

			}
			printf("\n");
		}
		count++; // 시행 횟수 증가
	}
	printf("원주율 ; %lf\n", pi);	// 최종 결과 출력


	return 0;
}