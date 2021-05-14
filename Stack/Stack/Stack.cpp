#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 10000 // 스택의 최대 크기

typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int capacity;
	int top;
}StackType;

//스택 초기
void init_stack(StackType* s) {
	s->top = -1;
	s->capacity = 0;
}

//공백 상태 검출 함수
int empty(StackType* s) {
	if (s->top == -1) {
		return 1;
	}
	else {
		return 0;
	}
}

// 삽입 함수
void push(StackType* s, element X) {
	s->capacity += 1;
	s->data[++(s->top)] = X;
}

//삭제 함수
element pop(StackType* s) {
	if (empty(s) == 1) {
		return -1;
	}
	else {
		s->capacity -= 1;
		return s->data[(s->top)--];
	}
}
// 크기를 알 수 있는 함수
element size(StackType* s) {
	return s->capacity;
}

// 스택의 가장 위에 있는 값을 확인하는 함수 
element top(StackType* s) {
	if (empty(s) == 1) {
		return -1;
	}
	else {
		return s->data[(s->top)];
	}
}

int main(void) {
	StackType s;
	init_stack(&s);
	int num = 0;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		char* str;                       // 수행하고 싶은 함수 문자열에 받기 위함. 
		str = malloc(sizeof(char) * 20);
		scanf("%s", str);
		if (strcmp(str, "push") == 0) {  // strcmp를 이용해 문자열 비교를 통해서 각각의 명령을 받아들이도록 설정
			int X;
			scanf("%d", &X);
			push(&s, X);
		}
		else if (strcmp(str, "pop") == 0) {
			printf("%d\n", pop(&s));
		}
		else if (strcmp(str, "empty") == 0) {
			printf("%d\n", empty(&s));
		}
		else if (strcmp(str, "top") == 0) {
			printf("%d\n", top(&s));
		}
		else if (strcmp(str, "size") == 0) {
			printf("%d\n", size(&s));
		}
	}
	return 0;
}