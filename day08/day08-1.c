#include <stdio.h>
#include <string.h>



// 문자열 예외처리
// 알파벳만 받을 수 있도록 문자열 확인 후,
// => 문자열에 하나라도 알파벳이 아닌 문자열이 있을 경우 0 반환 -> 문자열 재입력, 
// => 문자열이 모두 알파벳일때 -> 1 반환 문잔열 입력 완료
int isAlphabet(char* str) {
	for (int i = 0; i < strlen(str); i++) {
		char cur = *(str + i);
		if (!((cur >= 65 && cur <= 90) || (cur >= 97 && cur <= 122))) return 0;
	}
	return 1;
}




// 처음 구현 시도에서는 하나의 배열이 아닌 두 개의 배열을 이용하려 했으나 연산 이후 출력에서 문자열을 뒤집어 저장한 문자열에서 알 수 없는 값 계속 출력
// -> 이전에 했던 swab을 참고 하면 될것 같아 하나의 문자열을 쓰도록 변경
// tmp를 만들어 두는 것을 깜빡하여  "qwerty"를 입력했을 때 "ytrrty"가 출력되는 불상사 발생하기도 했었음
// 반복되서 사용되는 함수 시작에서 emd에 저장된 값 str + strlen(str) - 1을 end라는 별개의 함수에 담음, 겸사 겸사 str도 start라는 변수에 담아 의미를 부여했음
// 기존에는 for문이 작동하는 과저에서 start와 emd에 i를 더하고 빼는 것으로 다루는 값을 변경하였으나 
// for문의 코드 블록 마지막 쪽에 start와 end의 증감식을 배치하므로서 값을 바꾸는 과정을 더 간결하게 만들었음
void reverse_string(char* str) {
	char tmp;
	char* start = str;
	char* end = str + strlen(str) - 1;		// strlen() -> 문자열의 길이를 구하는 함수

	//for (int i = 0; i < strlen(str); i++) : 길이의 절반 만큼 반복함 -> 문자열 뒤집음 -> 그 만큼 더 진행 -> 다시 문자열 뒤집음(원상복귀)
	for (int i = 0; i < strlen(str) / 2; i++) {

		tmp = *start;	//*(start + i);		for문 마지막에서 start와 end의 값을 각각 증감 시켜 식을 더 E게 만드는 것이 더 보기 좋아 보인다고 생각

		*start = *end;	//*(start + i) = *(end - i);
		*end = tmp;		//*(end - i) = tmp;

		start++;
		end--;

	}
}

int main() {

	char str[100];

	do {
		printf("문자열을 입력하세요 : ");
		scanf_s("%s", &str, 100);
	} while (!isAlphabet(str));


	reverse_string(str);

	printf("뒤집어진 문자열 : %s", str);

	return 0;
}
