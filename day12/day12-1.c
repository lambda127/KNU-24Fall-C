#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


int main() {

    int topping[] = { 1, 2, 1, 3, 1, 4, 1, 2 }; //�׽�Ʈ�� �迭
    int topping_len = 8;
    int answer = 0;
    int check1[10001];
    int check2[10001];
    int kind1 = 0, kind2 = 0;


    

    for (int j = 0; j < 10001; j++) { // �迭 �ʱ�ȭ
        check1[j] = 0;
        check2[j] = 0;
    }

    for (int i = 0; i < topping_len; i++) { // ���� ���� �����ֱ�
        check2[topping[i]]++;
        if (check2[topping[i]] == 1)  kind2++; // ���� ���״µ� 1 -> ������ 0�̾��ٰ� ��� �ϳ� Ȯ�ε� �� -> ���� +1
    }

    for (int i = 0; i < topping_len; i++) { // �������
        check1[topping[i]]++;
        if (check1[topping[i]] == 1) kind1++;  // ���� ���״µ� 1 -> ������ 0�̾��ٰ� ��� �ϳ� Ȯ�ε� �� -> ���� +1

        check2[topping[i]]--;
        if (check2[topping[i]] == 0) kind2--;  // ���� ���״µ� 0 -> ������ 1�̾��ٰ� ��� �ϳ� ������ �� -> ���� -1


        if (kind1 == kind2)  answer++; 
        // ���̶� �����̶� ���� ���� ������ answer ����, for�� �ۿ� �״ٰ� ����� �����ϴµ� ���� ����� �ȳ��ͼ� ������ Ȯ���Ͽ���.

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





// ó������ �ϴ� �����ϰ� ����
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
     ���� for���� ����ؼ� �׷��� �ð��ʰ��� �ָ��� ����.
     �׷��� for���� ������ ����ص� ����for���� ���� ¥������ �Ͽ���
     ó���� �ߴ� ����� �պ��� ������ topping �迭�� ���鼭 �հ� �ڸ� ���� for���� ���ȴ�.
     �̰� ������ �� �� ���� for�� -> �ϴ� ���� �� ��ٰ� �ϳ��� �����鼭 ���ϴ� �ų�?
     => �������� �ϴ� �� �Ѱ���
     �ߺ��� Ȯ���ϴ� �迭�� ������ ������Ű�� �� ����( check2[topping[i]] )�� 1�̸� ���� ������ 0�̾��� �Ҹ��ϱ� ���ο� ������ ���� ��
     -> ������ ���� ������ ��Ÿ���� ������ ��(kind2)�� ������Ų��.

     �״����� �������׼� �ϳ��� ����ٰ� ������ �ϳ��� �ش�.
     => �������� ������� �Ŷ� ����� ����, ��� ������ ������ϴϱ� ������ �ݴ�� �ش��ϴ� ���� ���� ��Ų��. ���ҽ�Ű�鼭 ������ �پ������� �����Ѵ�.
     -> 0�̾��� 1�� �Ǹ� ������ �ϳ� ���� ���� ���̴�. �� �ݴ�� 1�̾��ٰ� 0�� �� �� �׷��Ƿ� �� ����( check2[topping[i]] ) �� 0�̸� ����(kind2)��  �ϳ� ���� ��Ų��.
    */