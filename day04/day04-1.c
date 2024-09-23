#include <stdio.h>

int main() {

	int num1 = 100, num2 = 100;
	int* pnum;

	pnum = &num1;
	(*pnum) += 30; //왜 (*pnum) 이렇게 괄호로 감쌌을까? -> 포인터 여러개를 쓸 때 '*'연산자와 혼동 되므로 ()로 감싸 가독성을 높임

	pnum = &num2;
	(*pnum) -=30;

	printf("num1 : %d\n", num1);
	printf("num2 : %d\n", num2);

	return 0;
}