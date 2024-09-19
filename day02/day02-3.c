#include <stdio.h>

int main() {
	int cnt = 1;

	for (int i = 0; i<= 99 ;i++) {
		if (i % 12 == 0 /*(i % 3 == 0 && i % 4 == 0)*/ || i % 7 == 0) {
			printf("%2d ", i);
			if (cnt == 6) {
				printf("\n");
				cnt = 0;
			}

			cnt++;
		}
	}

	return 0;
}