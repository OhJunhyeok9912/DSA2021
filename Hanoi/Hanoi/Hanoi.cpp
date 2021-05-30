#include <stdio.h>
#include <math.h>

void hanoi_tower(int n, char from, char tmp, char to) {
    if (n == 1) {
        printf("%c %c\n", from, to); // from에 있는 한 원판을 to로 옮긴다. 
    }
    else {
        hanoi_tower(n - 1, from, to, tmp);  // 맨 밑의 원판 제외 나머지 원판을 tmp로 이동
        printf("%c %c\n", from, to); // fromd에 있는 남은 원판 하나를 to로 이동
        hanoi_tower(n - 1, tmp, from, to); // tmp에 있던 원판들을 to로 옮긴다. 
    }
}

int main(void) {
    int num = 0;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        num = num + pow(2, i);
    }
    printf("%d\n", num);
    hanoi_tower(n, '1', '2', '3');
    return 0;
}