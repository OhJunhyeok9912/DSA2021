#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000
typedef struct {
    char data[MAX]; // 문자를 담는 배열 생성
    int top;
}Stack;

void init_stack(Stack* s) {
    s->top = -1;
}
int is_empty(Stack* s) {
    return s->top == -1;
}

int is_full(Stack* s) {
    return s->top == MAX - 1;
}

void push(Stack* s, char item) {
    if (is_full(s)) return;
    else s->data[++(s->top)] = item;
}

char pop(Stack* s) {
    if (is_empty(s)) exit(1);
    else return s->data[(s->top)--];
}

int solution(const char* s) {
    char ch, open_ch;
    int answer = 0; // 올바른 문자열이 되는 개수를 반환
    int cnt = 0; // push하는 수를 저장하는 변수 생성
    Stack stack; // 스택을 생성. 스택에는 왼쪽 괄호만 담는다. 
    init_stack(&stack);
    for (int j = 0; j < strlen(s); j++) { // 한 문자열에 대해 회전할 수있는 수는 문자열의 길이 만큼이므로 총 n*n만큼 반복되어야 한다. 
        for (int i = 0; i < strlen(s); i++) { 
            ch = s[(i + j) % strlen(s)]; // 문자열이 바뀔 때마다 시작 인덱스를 1씩 늘리면 문자열을 1번 회전하는 것과 같기 때문에 시작 인덱스를 (i + j) % strlen(s)로 설정
            switch (ch) {
            case'(':case'[':case'{':
                push(&stack, ch);
                ++cnt; // push할 때 마다 카운팅한다. }}}와 같은 문자열은 괄호가 스택에 한 번도 들어가지 않기 때문이다. 
                break;
            case')':case']':case'}':
                if (is_empty(&stack)) break; // 닫는 괄호 차례에서 스택이 비어있다면 이 문자열은 올바른 문자열이 아니기 때문에 이번 실행을 중단해야한다. 
                else {
                    open_ch = pop(&stack); // 닫는 괄호와 스택에서 꺼낸 여는 괄호와 비교
                    if ((open_ch == '(' && ch != ')') ||
                        (open_ch == '[' && ch != ']') ||
                        (open_ch == '{' && ch != '}')) {
                        return 0; // 짝이 맞다면 0을 반환한다. 
                    }
                    break; 
                }
            }
        }
        if (!is_empty(&stack) || cnt == 0) { // 스택이 비어있지 않고 한번도 여는괄호가 스택에 들어가지 않았다면 잘못된 문자열이다.
            while (!is_empty(&stack)) pop(&stack); // 스택의 재활용을 위해 스택 내부를 모두 비운다.
        }
        else ++answer; // 그 이외는 올바른 문자열이므로 1 카운팅한다. 
    }
    return answer;
}
int main() {
    char string[1000];
    scanf_s("%s", string);
    int answer = solution(string);
    printf("%d\n", answer);
}