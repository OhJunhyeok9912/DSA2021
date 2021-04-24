#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100 // 스택의 최대 크기

typedef char element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
}StackType;

//스택 초기
void init_stack(StackType* s) {
	s->top = -1;
}

//공백 상태 검출 함수
int is_empty(StackType* s) {
	return (s->top == -1);
}
// 포화 상태 검출 함수
int is_full(StackType* s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}
// 삽입 함수
void push(StackType* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else s->data[++(s->top)] = item;
}
//삭제 함수
element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}
// 괄호 검사 함수
int check_matching(const char* in) {
	StackType s;
	char ch, open_ch;
	int i, n = strlen(in);
	init_stack(&s);

	for (i = 0; i < n; i++) {
		ch = in[i];
		switch (ch) {
		case '(':
			push(&s, ch);
			break;
		case ')':
			if (is_empty(&s)) return 0;
			else {
				open_ch = pop(&s);
				if (open_ch == '(' && ch != ')') {
					return 0;
				}
				break;
			}
		}
	}
	if (!is_empty(&s)) return 0;
	return 1;
}

int main(void) {
	int num = 0;
	scanf_s("%d", &num); // 반복할 횟수 받기
	char* p = malloc(sizeof(char) * 50);  // 동적 메모리 활동
	for (int i = 0; i < num; i++) {
		scanf_s("%s", p); // 문장 받기
		if (check_matching(p) == 1) { // p 괄호 확인하기 반환값이 1이라면 yes
			printf("YES\n");
		}

		else {
			printf("NO\n"); //아니라면 no
		}
	}
	free(p);  // 메모리 반환
	return 0;
}