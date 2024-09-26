#include <stdio.h>
#include <stdlib.h>

int main() {

	int n;
	int* list_number;
	char** list_name;  // 이중 포인터 안쓰려면 : char* list_name;
	int* list_score;

	printf("학생 수 입력 : ");
	scanf_s("%d", &n);
	printf("--------------------------------------------------------------\n\n");

	list_number = (int*)malloc(sizeof(int) * n);
	list_score = (int*)malloc(sizeof(int) * n);
	list_name = (char**)malloc(sizeof(char*) * n);
	for (int i = 0; i < n; i++) {
		list_name[i] = (char*)malloc(sizeof(char) * 100);
	}
	/*이중 포인터 안쓰려면
	list_name = (char*)malloc(sizeof(char) *100 * n);
	*/

	


	for (int i = 0; i < n; i++) {
		printf("<%d번 학생>\n", i+1);

		printf("학번 : ", i + 1);
		scanf_s("%d", &list_number[i]);

		printf("이름 : ", i + 1);
		scanf_s("%s", list_name[i], sizeof(list_name[i])/*크기 그냥 100쓰면 되긴해*/); //이중 포인터 안쓰려면 : scanf_s("%s", list_name+(100*i), 100);
		printf("%점수 : ", i + 1);
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

	printf("최댓값 : %d\n최솟값 : %d\n평균 : %d\n", max, min, avr);
	printf("--------------------------------------------------------------\n\n");


	for (int i = 0; i < n; i++) {
		free(list_name[i]);
	} // 이중 포인터 안쓰려면 : 이거 없음.
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