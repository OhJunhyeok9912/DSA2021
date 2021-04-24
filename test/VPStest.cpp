#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50
typedef char element; // (, ) ���� ��ҷ� �����Ƿ� char�� element�� �Ѵ�.
typedef struct {
    element data[MAX];
    int top;
}Stack; // ������ ����ü�� �����ؼ� ����Ѵ�. 
/* typedef enum {
    false = 0,
    true = 1
} bool; ���ؿ����� bool�� ����ϱ� ���ؼ� ������ ���� �����ؾ� �Ѵ�. ��ó: https://blog.naver.com/maxx1027/221495146988*/

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

bool checkVPS(Stack* s, const char str[]) { // VPS�� �´��� �ƴ��� boolŸ������ �Ǵ��ϰ� �Ű������� ���ð� ���ڿ��� ��� 
    for (int i = 0; i < strlen(str); i++) { // �Է¹��� ���ڿ��� ���� ��ŭ �ݺ�
        if (str[i] == '(') push(s, str[i]); // ( �� �Է� ������ ���ÿ� ����, (�� ���ÿ� ����
        else if ((str[i] == ')')) { // (�� ���� �� �ִ� ���ÿ� �ƹ��͵� ���� �� VPS�� �ƴ��� ����
            if (is_empty(s)) {
                printf("NO\n");
                return false; // false�� ��ȯ
            }
            else pop(s); // (�� ���� �� �ִ� ���ÿ� (�� ���� �� ( ) �� �� ���� �̷�� ������ pop�Ѵ�
        }
    }
    if (s->top == -1) printf("YES\n"); // ( )�� ���� �� ���� �̷� ���ÿ� �ƹ��͵� ���� �� YES�� ���
    else if (s->top > -1) // ���ÿ� ���� ���� ���� �� ����
    {
        printf("NO\n"); return false; //()�� ���� �̷�� ����(�� �ֱ� ������ NO�� ��� �� false�� ��ȯ
    }
    return true; // YES�� ��쿡 �ٷ� return�� �ϸ� else if���� �����Ǵ��� �� �� �����Ƿ� �������� ��ȯ
}

int main() {
    Stack stack; // ������ �������� ����
    init_stack(&stack); // ������ �ʱ�ȭ
    int casenums;
    scanf_s("%d", &casenums); // �׽�Ʈ �������� ������ �Է� ����;
    for (int i = 1; i <= casenums; i++) { // �׽�Ʈ �������� ������ŭ �ݺ�
        char p[MAX]; // �ִ� ���� ��ŭ ���� �迭�� ����
        scanf_s("%s", p); // ���ڿ��� �Է¹���
        if (checkVPS(&stack, p) == false) // VPS���� �Ǵ��ϰ� ������ �� ����
        {
            while (!is_empty(&stack))
            {
                pop(&stack); // ���ÿ� ���� (�� ���� ��찡 �ֱ� ������ ������ �ʱ�ȭ�Ѵ�. 
            }
        }
    }
    return 0;
}