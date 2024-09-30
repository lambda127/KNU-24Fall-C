
//Monte Carlo Algorithm

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define BILLION 1000000000

int main() {

	double x = 0;
	double y = 0;
	double pi = 0;
	

	int count = 1, circle = 0;
	int rate = 0;

	srand(time(NULL));

	while (count <= BILLION) {

		x = (double)rand() / (double)RAND_MAX;
		y = (double)rand() / (double)RAND_MAX;

		if (sqrt(pow(x, 2) + pow(y, 2)) < 1) circle++;

		if (count % (BILLION/100) == 0) {
			rate = count / (BILLION / 100);

			pi = 4 * ((double)circle / (double)count);

			printf("%d%%진행.. 원주율 : %lf ", rate, pi);

			for (int i = 0; i < 20; i++) {

				if (i < (rate / 5)) {
					printf("■");
				}
				else {
					printf("□");
				}

			}
			printf("\n");
		}
		count++;
	}
	printf("원주율 ; %lf\n", pi);


	return 0;
}