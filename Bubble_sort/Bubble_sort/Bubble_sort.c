#include <stdio.h>
#include <string.h>

void sort_strings(char* list[], int size) { // 버블정렬
    int i, j, least;
    char* temp;

    for (i = 0; i < size - 1; i++) {
        least = i;   // i번째 값을 최소로 두기  
        for (j = i + 1; j < size; j++) { // 최소값 탐색
            if (strcmp(list[j], list[least]) < 0) // 
                least = j;
        }
        temp = list[i]; // i번째 요소와 least위치의 요소를 교환
        list[i] = list[least];
        list[least] = temp;
    }
}

int main(void) {
    char* string[3] = { "mycopy", "src", "dst" }; // 포인터 배열로 저장
    int size = sizeof(string) / sizeof(string[0]);
    sort_strings(string, size);  // 버블 정렬 
    for (int i = 0; i < size; i++) {
        printf("%s\n", string[i]);
    }
    return 0;
}


