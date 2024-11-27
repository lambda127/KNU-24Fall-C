#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

int sol(int n) {
	int ans = 0;

	//의외로? 규칙 찾는 건 A4 한 장도 다 안 씀
	if (n == 1 || n == 2 || n & 2 == 0) { // (이게 어려웠다)2의 거듭제곱인 수는 다른 2의 거듭제곱과 AND 비트 연산을 했을 때 0이 나옴 -> n을 2와 비교해서 0이면 2의 걷브 제곱이다.(2는 따로 확인)
		// n=1인 경우, 한번 점프
		// 2의 걷브 제곱의 경우 점프를 한번하고 그 이후엔 목적지까지 순간이동하면 도착
		ans = 1;  
	}
	else if (n % 2 == 0) { // 2의 거듭제곱을 제외한 짝수일 때
		// 짝수는 n/2일 때와 점프 횟수가 동일하다.
		// n/2일 때의 횟수를 모르므로 재귀를 돌린다.
		ans = sol(n/2);
	}
	else { // 모든 경우 이외의 n!=1인 홀수일 때
		// n-1의 값(바로 이전 짝수 값) + 1이다.
		ans = sol(n-1) + 1;
	}

	return ans;
}

int main() {
	int n = 5;
	int ans = 0;

	ans = sol(n);

	printf("ans : %d\n", ans);

	return 0;
}