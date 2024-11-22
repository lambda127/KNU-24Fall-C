#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

double f_x(double x) {
	double value = 0;

	value = sin(x) - log10(1/x); //pow(x, 2) + 1;

	return value;
}

double integral(double s, double e, int n) {
	double result = 0;
	double range = e - s, interv = 0;
	double x = s;


	for (int j = 0; j <= n; j++) {
		x = s;
		result = 0;
		interv = range / pow(2, j);

		for (int i = 1; i <= pow(2, j); i++) {
			result += (f_x(x) * interv); // f(x_(n-1)) * (x_n - x_(n-1))을 하여야 출력 예시와 동일하게 나옴

			x += interv; // 그래서 원래 앞에 두었는데 뒤로 보냄
			
		}
		
		printf("구간 : %10d | 적분 결과 : %10.6lf\n", (int)pow(2, j), result);
	}
	

	return result;
}


int main() {
	double s, e;
	int n;

	printf("Input start value : ");
	scanf_s("%lf", &s);

	printf("Input end value : ");
	scanf_s("%lf", &e);


	printf("Input n (2^n) : ");
	scanf_s("%d", &n);

	printf("------------------------------------------\n");
	integral(s, e, n); 
	printf("------------------------------------------\n");


	return 0;
}