#include <stdio.h>

// 벡터 구조체
struct Vector {
	int x, y, z;
};

// 벡터 합 연산
void vAdd(struct Vector v1, struct Vector v2) {
	struct Vector result;

	result.x = v1.x + v2.x;
	result.y = v1.y + v2.y;
	result.z = v1.z + v2.z;

	printf("벡터의 합은  x : %d, y : %d, z : %d\n", result.x, result.y, result.z);
}

// 벡터 차 연산
void vSub(struct Vector v1, struct Vector v2) {
	struct Vector result;

	result.x = v1.x - v2.x;
	result.y = v1.y - v2.y;
	result.z = v1.z - v2.z;

	printf("벡터의 차는  x : %d, y : %d, z : %d\n", result.x, result.y, result.z);
}

// 벡터 내적 연산
void vDProduct(struct Vector v1, struct Vector v2) {
	int result;

	result = (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);

	printf("벡터의 내적은  v1 · v2 = %d\n", result);
}

// 벡터 외적 연산
void vCProduct(struct Vector v1, struct Vector v2) {
	struct Vector result;

	result.x = (v1.y * v2.z) - (v1.z * v2.y);
	result.y = (v1.z * v2.x) - (v1.x * v2.z);
	result.z = (v1.x * v2.y) - (v1.y * v2.x);

	printf("벡터의 외적은  x : %d, y : %d, z : %d\n", result.x, result.y, result.z);
}


int main() {
	struct Vector v1;
	struct Vector v2;
	int sel = 0;			// 기능 선택용 변수

	// 벡터 입력
	printf("첫번째 벡터(x,y,z) : ");
	scanf_s("%d, %d, %d", &v1.x, &v1.y, &v1.z);

	printf("두번째 벡터(x,y,z) : ");
	scanf_s("%d, %d, %d", &v2.x, &v2.y, &v2.z);

	// 입력된 벡터 출력
	printf("입력된 첫번째 벡터 : %d, %d, %d\n", v1.x, v1.y, v1.z);
	printf("입력된 두번째 벡터 : %d, %d, %d\n", v2.x, v2.y, v2.z);

	printf("\n\n-----------------------------------------\n");
	
	printf("1. 벡터의 합\n2. 벡터의 차\n3. 벡터의 내적\n4. 벡터의 외적\n5. 종료\n"); // 기능 출력

	while (1) {
		printf("-----------------------------------------\n");

		printf("명령 입력 : ");
		scanf_s("%d", &sel);

		switch (sel) {
		case 1:	// 합
			vAdd(v1, v2);
			break;

		case 2:	// 차
			vSub(v1, v2);
			break;

		case 3:	// 내적
			vDProduct(v1, v2);
			break;

		case 4:	// 외적
			vCProduct(v1, v2);
			break;

		case 5:	// 프로그램 종료
			printf("프로그램을 종료합니다.\n");
			printf("-----------------------------------------\n");
			return;

		default: // 1~5 이외의 숫자 입력시 예외 처리
			printf("없는 기능입니다.\n");
			break;

		}
	}
	return 0;
}