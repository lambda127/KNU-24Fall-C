#include <stdio.h>
#include <stdlib.h>

int main() {

	int n;
	int* list_number;
	char** list_name;  // ���� ������ �Ⱦ����� : char* list_name;
	int* list_score;

	printf("�л� �� �Է� : ");
	scanf_s("%d", &n);
	printf("--------------------------------------------------------------\n\n");

	list_number = (int*)malloc(sizeof(int) * n);
	list_score = (int*)malloc(sizeof(int) * n);
	list_name = (char**)malloc(sizeof(char*) * n);
	for (int i = 0; i < n; i++) {
		list_name[i] = (char*)malloc(sizeof(char) * 100);
	}
	/*���� ������ �Ⱦ�����
	list_name = (char*)malloc(sizeof(char) *100 * n);
	*/

	


	for (int i = 0; i < n; i++) {
		printf("<%d�� �л�>\n", i+1);

		printf("�й� : ", i + 1);
		scanf_s("%d", &list_number[i]);

		printf("�̸� : ", i + 1);
		scanf_s("%s", list_name[i], sizeof(list_name[i])/*ũ�� �׳� 100���� �Ǳ���*/); //���� ������ �Ⱦ����� : scanf_s("%s", list_name+(100*i), 100);
		printf("%���� : ", i + 1);
		scanf_s("%d", &list_score[i]);

		printf("--------------------------------------------------------------\n\n");
	}

	int max = list_score[0], min = list_score[0], sum = 0, avr;

	for (int i = 0; i < n; i++) {
		if (list_score[i] > max)  max = list_score[i];
		if (list_score[i] < min) min = list_score[i];
		sum += list_score[i];
	}

	avr = sum / n;

	printf("�ִ� : %d\n�ּڰ� : %d\n��� : %d\n", max, min, avr);
	printf("--------------------------------------------------------------\n\n");


	for (int i = 0; i < n; i++) {
		free(list_name[i]);
	} // ���� ������ �Ⱦ����� : �̰� ����.
	free(list_name);
	free(list_number);
	free(list_score);
	
	list_name = NULL;
	list_number = NULL;
	list_score = NULL;
	for (int i = 0; i < n; i++) {
		list_name[i] = NULL;
	}

	return 0;
}