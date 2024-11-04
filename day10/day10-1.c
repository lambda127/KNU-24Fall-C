#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Node {
	char name[20];
	int score;
	struct Node* next;
};

struct Node* head = NULL;


struct Node* create_node(char name[20], int score) {
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	strcpy_s(new_node->name, sizeof(name), name);
	new_node->score = score;
	new_node->next = NULL;

	return new_node;
}

int insert_node(struct Node* new_node) {
	struct Node* prev;
	struct Node* cur;

	prev = head;
	cur = head->next;

	while (cur != NULL) {

		if (new_node->score > cur->score) {
			prev->next = new_node;
			new_node->next = cur;
			return 1;
		}

		prev = cur;
		cur = cur->next;
	}

	if (cur == NULL) {
		prev->next = new_node;
		return 2;
	}

	return 0;
	
}


void print_node() {
	struct Node* cur = head->next;

	while (cur != NULL) {
		printf("%s\t:\t%d\n", cur->name, cur->score);

		cur = cur->next;
	}
}

void delete_node(char name[20]) {
	struct Node* prev = head;
	struct Node* cur;

	cur = head->next;

	while (cur != NULL) {
		if (strcmp(cur->name, name) == 0) { // ������ cur->name == name���� ���Ͽ��µ� �̴� �� ������ �ּҰ��� ���ϴ� ���̹Ƿ� ��������
			prev->next = cur->next;
			free(cur);
		}

		prev = cur;
		cur = cur->next;
	}

}


void free_node(struct Node* node) {
	struct Node* cur = node;
	struct Node* next = cur->next;

	while (next != NULL) {
		free(cur);
		cur = next;
		next = next->next;
	}
}

int main() {
	head = (struct Node*)malloc(sizeof(struct Node));
	head->next = NULL;
	
	char name[20];
	int score;
	int input;


	while (1) {
		printf("1. �л��� ������ �Է�\n");
		printf("2. �л��� ���� ����\n");
		printf("3. ���α׷� ����\n");

		printf("input : ");
		scanf_s("%d", &input);

		switch (input) {
		case 1:
			printf("�л��� �̸� : ");
			scanf_s("%s", name, 20);
			printf("%s�� ���� : ", name);
			scanf_s("%d", &score);

			insert_node(create_node(name, score));
			break;

		case 2:
			printf("�л��� �̸� : ");
			scanf_s("%s", name, 20);

			delete_node(name);
			break;

		case 3:
			return;

		default:

			break;
		}

		printf("---------------------------------------\n");
		print_node();
		printf("---------------------------------------\n");
	}


	free_node(head);
	return 0;
}