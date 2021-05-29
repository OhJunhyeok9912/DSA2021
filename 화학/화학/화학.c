#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

#define MAX_STACK_SIZE 101

typedef int element; // 정수를 담음
typedef struct StackType {
	element data[MAX_STACK_SIZE]; // 정수를 담는 배열 생성
	int top;
} StackType;

// 스택 초기화 함수
void init_stack(StackType* s)
{
	s->top = -1;
}

// 공백 상태 검출 함수
int is_empty(StackType* s)
{
	return (s->top == -1);
}
// 포화 상태 검출 함수
int is_full(StackType* s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}
// 삽입함수
void push(StackType* s, element item)
{
	if (is_full(s)) return;
	else s->data[++(s->top)] = item;
}
// 삭제함수
element pop(StackType* s)
{
	if (is_empty(s)) exit(1);

	else return s->data[(s->top)--];
}
// 피크함수
element peek(StackType* s)
{
	if (is_empty(s)) exit(1);
	else return s->data[s->top];
}
int main() {
	StackType s;
	init_stack(&s); // 스택 초기화 
	char formula[MAX_STACK_SIZE] = {'\0'}; // 화학식을 담을 배열 생성 및 초기화
	int sum = 0; // 화학식량 
	int psum = 0; // 괄호 안에 있는 화학식량
	scanf("%s", formula); 
	for (int i = 0; i < strlen(formula); i++) {
		switch (formula[i]) { 
		case 'H':   push(&s,  1);  break;
		case 'O':  push(&s, 16);  break;
		case 'C':  push(&s, 12);  break;
		case '(':  push(&s, 0);  break; // 여는 괄호 구분을 위해 0을 삽입
		case ')': if (is_empty(&s)) break; // 괄호가 비었다면 잘 못된 화학식
				else {
			while (peek(&s) != 0) { // 0을 만날때 까지 합하기
				psum += pop(&s); 
			} 
			pop(&s); // 합이 끝난 후 (를 pop
			push(&s, psum); // 괄호 안에 계산한 양을 다시 삽입 
		}
				psum = 0; // 다시 사용하기 위해 초기화 
				break;
		default: s.data[s.top] *= (formula[i] - '0');  break; // top에 있는 양을 n배
		}
	}
	while (!is_empty(&s)) {
		sum += pop(&s); // 스택에 있는 모든 수를 합
	}

	printf("%d\n", sum);

	return 0;
}