#include <stdio.h>

// ����ü ����
struct Product {
	int id;
	char name[100];
	int price;
};

// �Էµ� ��ǰ ��� : �Ű����� -> Product(����ü) �迭 = �Էµ� ��ǰ ����Ʈ, cnt = �Էµ� ��ǰ�� ����
void printProduct(struct Product p) {
	
	printf("��ǰ ID : %d\n", p.id);
	printf("��ǰ�� : %s\n", p.name);
	printf("���� : %d ��\n", p.price);
	printf("\n");
}

int main() {
	struct Product list[5];
	int cnt = 0;

	// ��ǰ�� 5���� �Էµ� ������ �ݺ�
	while (cnt < 5) {
		printf("��ǰ ������ �Է��ϼ��� (�Է� �ߴ��� id�� 0�Է�)\n");
		printf("��ǰ ID : ");
		scanf_s("%d", &list[cnt].id); // ��ǰ ID �Է�

		if (list[cnt].id == 0) break; // �Է� ���� ID ���� 0�̸� �ݺ� Ż��

		printf("��ǰ�� : ");
		scanf_s("%s",list[cnt].name, sizeof(list[cnt].name));	// ��ǰ�� �Է�

		printf("���� : ");
		scanf_s("%d", &list[cnt].price);	// ���� �Է�

		printf("\n");

		cnt++; // ��ǰ ���� ����
	}

	printf("\n");
	printf("<<�Էµ� ��ǰ ���>>\n");	// �ݺ� ���� �� Ż��� �Էµ� ��ǰ ����Ʈ ���
	for (int i = 0; i < cnt; i++) {
		printProduct(list[i]);
	}
	

	return 0;
}