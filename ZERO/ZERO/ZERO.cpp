#include <stdio.h>
#include <stdlib.h>
#define MAX 100000

typedef int element;
typedef struct {
	element data[MAX];
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

void push(Stack* s, element item) {
	if (is_full(s)) return;
	else s->data[++(s->top)] = item;
}

element pop(Stack* s) {
	if (is_empty(s)) exit(1);
	else return s->data[(s->top)--];
}

int main() {
	int k, num;
	int sum = 0;
	Stack s; init_stack(&s);
	scanf_s("%d", &k);
	for (int i = 0; i < k; i++) {
		scanf_s("%d", &num);
		if (num == 0) pop(&s);
		else push(&s, num);
	}
	for (int i = s.top; i >= 0; i--) {
		sum += pop(&s);
	}
	printf("\n%d\n", sum);
	return 0;
}
