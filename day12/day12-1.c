#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


int main() {

    int topping[] = { 1, 2, 1, 3, 1, 4, 1, 2 }; //테스트용 배열
    int topping_len = 8;
    int answer = 0;
    int check1[10001];
    int check2[10001];
    int kind1 = 0, kind2 = 0;


    

    for (int j = 0; j < 10001; j++) { // 배열 초기화
        check1[j] = 0;
        check2[j] = 0;
    }

    for (int i = 0; i < topping_len; i++) { // 동생 한테 몰아주기
        check2[topping[i]]++;
        if (check2[topping[i]] == 1)  kind2++; // 증가 시켰는데 1 -> 이전에 0이었다가 방금 하나 확인된 것 -> 종류 +1
    }

    for (int i = 0; i < topping_len; i++) { // 뺏어오기
        check1[topping[i]]++;
        if (check1[topping[i]] == 1) kind1++;  // 증가 시켰는데 1 -> 이전에 0이었다가 방금 하나 확인된 것 -> 종류 +1

        check2[topping[i]]--;
        if (check2[topping[i]] == 0) kind2--;  // 감소 시켰는데 0 -> 이전에 1이었다가 방금 하나 삭제된 것 -> 종류 -1


        if (kind1 == kind2)  answer++; 
        // 형이랑 동생이랑 종류 개수 같으면 answer 증가, for문 밖에 뒀다가 제대로 동작하는데 답이 제대로 안나와서 여러번 확인하였다.

        /*
        for (int j = 0; j < 5; j++) {
            printf("%d\t%d\t%d\n", j, check1[j], check2[j]);
        }
        printf("\nkind :\t%d\t%d\n\n", kind1, kind2);
        */
        
    }



    printf("answer : %d\n", answer);


	return 0;
}





// 처음에는 일단 무식하게 시작
    /*
    for (int i = 1; i < topping_len - 1; i++) {

        kind1 = 0, kind2 = 0;

        for (int j = 0; j < 10001; j++) {
            check1[j] = 0;
            check2[j] = 0;
        }


        for (int j = 0; j < i; j++) {
            check1[topping[j]]++;
        }

        for (int j = i; j < topping_len; j++) {
            check2[topping[j]]++;

        }

        for (int j = 0; j < 10001; j++) {

            if (check1[j] > 0) {
                kind1++;
            }

            if (check2[j] > 0) {
                kind2++;
            }
        }

        if (kind1 == kind2) {
            answer++;
        }

    }


    */
    /*
     이중 for문을 사용해서 그런지 시간초과가 주르륵 떴다.
     그랫서 for문을 여러개 사용해도 이중for문은 없게 짜보려고 하였음
     처음에 했던 방식이 앞부터 끝까지 topping 배열을 돌면서 앞과 뒤를 각각 for문을 돌렸다.
     이게 문제가 된 게 이중 for문 -> 일단 동생 다 줬다가 하나씩 뱄으면서 비교하는 거네?
     => 동생한테 일단 다 넘겨줌
     중복을 확인하는 배열에 개수를 증가시키고 그 숫자( check2[topping[i]] )가 1이면 증가 전에는 0이었단 소리니깐 새로운 종류가 들어온 것
     -> 동생이 가진 종류를 나타내는 변수의 값(kind2)을 증가시킨다.

     그다음에 동생한테서 하나씩 뺐어다가 형한테 하나씩 준다.
     => 동생한테 몰아줬던 거랑 방식은 동일, 대신 동생걸 뺐어야하니깐 동생은 반대로 해당하는 값을 감소 시킨다. 감소시키면서 종류가 줄어드는지를 봐야한다.
     -> 0이었다 1이 되면 종류가 하나 새로 생긴 것이다. 그 반대는 1이었다가 0이 된 것 그러므로 그 개수( check2[topping[i]] ) 가 0이면 종류(kind2)를  하나 갑소 시킨다.
    */