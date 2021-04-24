#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50
typedef char element; // (, ) 만을 요소로 가지므로 char을 element로 한다.
typedef struct {
    element data[MAX];
    int top;
}Stack; // 스택을 구조체로 정의해서 사용한다. 
/* typedef enum {
    false = 0,
    true = 1
} bool; 백준에서는 bool을 사용하기 위해선 다음과 같이 정의해야 한다. 출처: https://blog.naver.com/maxx1027/221495146988*/

void init_stack(Stack* s) {
    s->top = -1;
}

int is_empty(Stack* s) {
    return s->top == -1;
}

int is_full(Stack* s) {
    return s->top == MAX - 1;
}

void push(Stack* s, element item) {
    if (is_full(s)) return;
    else s->data[++(s->top)] = item;
}

element pop(Stack* s) {
    if (is_empty(s)) {
        exit(1);
    }
    return s->data[(s->top)--];
}

bool checkVPS(Stack* s, const char str[]) { // VPS가 맞는지 아닌지 bool타입으로 판단하고 매개변수로 스택과 문자열을 사용 
    for (int i = 0; i < strlen(str); i++) { // 입력받은 문자열의 길이 만큼 반복
        if (str[i] == '(') push(s, str[i]); // ( 를 입력 받으면 스택에 저장, (만 스택에 저장
        else if ((str[i] == ')')) { // (만 담을 수 있는 스택에 아무것도 없을 때 VPS가 아님을 실행
            if (is_empty(s)) {
                printf("NO\n");
                return false; // false를 반환
            }
            else pop(s); // (만 담을 수 있는 스택에 (가 있을 때 ( ) 가 한 쌍을 이루기 때문에 pop한다
        }
    }
    if (s->top == -1) printf("YES\n"); // ( )가 전부 한 쌍을 이루어서 스택에 아무것도 없을 때 YES를 출력
    else if (s->top > -1) // 스택에 남은 것이 있을 때 실행
    {
        printf("NO\n"); return false; //()가 쌍을 이루고 남는(가 있기 때문에 NO를 출력 후 false를 반환
    }
    return true; // YES인 경우에 바로 return을 하면 else if문의 조건판단을 할 수 없으므로 마지막에 반환
}

int main() {
    Stack stack; // 스택을 정적으로 생성
    init_stack(&stack); // 스택을 초기화
    int casenums;
    scanf_s("%d", &casenums); // 테스트 데이터의 개수를 입력 받음;
    for (int i = 1; i <= casenums; i++) { // 테스트 데이터의 개수만큼 반복
        char p[MAX]; // 최대 개수 만큼 문자 배열을 생성
        scanf_s("%s", p); // 문자열을 입력받음
        if (checkVPS(&stack, p) == false) // VPS인지 판단하고 거짓일 때 실행
        {
            while (!is_empty(&stack))
            {
                pop(&stack); // 스택에 남은 (가 있을 경우가 있기 때문에 스택을 초기화한다. 
            }
        }
    }
    return 0;
}