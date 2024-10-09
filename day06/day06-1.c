#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* link;
};

struct Node* head = NULL;

struct Node* create_node(int data) {

	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = data;
	new_node->link = NULL;

	return new_node;
}

struct Node* last_node() {
	struct Node* cur = head;
	while (cur->link != NULL) {
		cur = cur->link;
	}

	return cur;
}

void insert_node_last(struct Node* new_node) {
	struct Node* last = last_node();
	last->link = new_node;
}


void print_node() {
	struct Node* cur = head->link;
	while (cur != NULL) {
		printf("%d\n", cur->data);
		cur = cur->link;
	}
}

struct Node* find_node(int value) {
	struct Node* cur = head->link;
	while (cur != NULL) {
		if (cur->data == value) return cur;

		cur = cur->link;
	}

	return NULL;
}


int delete_node(int value) {
	struct Node* pre_node = head;
	struct Node* cur = head->link;

	while (cur != NULL) {
		if (cur->data == value) {
			pre_node->link = cur->link;
			free(cur);
			return 1;
		}

		pre_node = cur;
		cur = cur->link;
	}

	return 0;
}


int main() {

	head = (struct Node*)malloc(sizeof(struct Node));
	head->link = NULL;

	insert_node_last(create_node(1)); //����� ����
	insert_node_last(create_node(2));
	insert_node_last(create_node(3));
	insert_node_last(create_node(4));
	insert_node_last(create_node(5));

	print_node(); //���Ḯ��Ʈ ���(����� ��� ��� ���)

	delete_node(3); //��� ����(3��°)(��Ȯ���� 3�� ���� ���� ��� ����)

	print_node(); //���Ḯ��Ʈ ���

	free(head);
	return 0;
}