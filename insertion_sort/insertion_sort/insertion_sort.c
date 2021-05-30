#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int* list, int num) { // 삽입 정렬
    int i, j, key;
    for (i = 1; i < num; i++) {
        key = list[i];  // i번째 정수를 key변수로 복사 
        for (j = i - 1; j >= 0 && list[j] > key; j--) {  // 
            list[j + 1] = list[j]; // ㅓ번째를 j+1번째로 이동한다. 
        }
        list[j + 1] = key;  // j번째 정수가 key보다 작으므로 j+1번째가 key값이 들어갈 위치이다. 
    }
}

int main(void) {
    int num;
    scanf("%d", &num);
    int* list;
    list = malloc(sizeof(int) * num);
    for (int i = 0; i < num; i++) {
        scanf("%d", &list[i]);
    }
    insertion_sort(list, num);
    for (int i = 0; i < num; i++) {
        printf("%d\n", list[i]);
    }

    return 0;
}
