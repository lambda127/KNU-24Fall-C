#include <stdio.h>

// 구조체 정의
struct Product {
	int id;
	char name[100];
	int price;
};

// 입력된 상품 출력 : 매개변수 -> Product(구조체) 배열 = 입력된 상품 리스트, cnt = 입력된 상품의 갯수
void printProduct(struct Product p) {
	
	printf("상품 ID : %d\n", p.id);
	printf("상품명 : %s\n", p.name);
	printf("가격 : %d 원\n", p.price);
	printf("\n");
}

int main() {
	struct Product list[5];
	int cnt = 0;

	// 상품이 5개가 입력될 때까지 반복
	while (cnt < 5) {
		printf("상품 정보를 입력하세요 (입력 중단은 id에 0입력)\n");
		printf("상품 ID : ");
		scanf_s("%d", &list[cnt].id); // 상품 ID 입력

		if (list[cnt].id == 0) break; // 입력 받은 ID 값이 0이면 반복 탈출

		printf("상품명 : ");
		scanf_s("%s",list[cnt].name, sizeof(list[cnt].name));	// 상품명 입력

		printf("가격 : ");
		scanf_s("%d", &list[cnt].price);	// 가격 입력

		printf("\n");

		cnt++; // 상품 갯수 증가
	}

	printf("\n");
	printf("<<입력된 상품 목록>>\n");	// 반복 종료 및 탈출시 입력된 상품 리스트 출력
	for (int i = 0; i < cnt; i++) {
		printProduct(list[i]);
	}
	

	return 0;
}