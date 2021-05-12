#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STACK_MAX 100

typedef int element;
typedef struct Stack {
	element data[STACK_MAX];
	element time[STACK_MAX];
	int top;
}Stack; // 스택에 점수와 시간을 담는 배열을 두개 생성한다. 

void init_stack(Stack* s) {
	s->top = -1;
}

int is_full(Stack* s) {
	return s->top == STACK_MAX - 1;
}

int is_empty(Stack* s) {
	return s->top == -1;
}

void push(Stack* s, element item, element time) {
	if (is_full(s)) return;
	else {
		s->data[++(s->top)] = item;
		s->time[s->top] = time;
	}
} // 스택에 데이터를 담을 때 매개변수는 스택, 점수, 시간이 되어야하고 이 데이터들을 배열에 담는다. 

element pop(Stack* s) {
	if (is_empty(s)) return -1;
	else {
		return s->data[(s->top)--];
	}
} // 실질적으로 점수를 알아야 하기 때문에 time 배열에서는 꺼낼 필요가 없다. 

int main() {
	Stack s;
	init_stack(&s);
	int mins = 0;
	int assignmentyn = 0;
	int score = 0;
	int min = 0;
	int sum = 0; // 총 시간, 과제여부, 점수, 과제에 할당된 시간 , 총 점수의 변수 선언 및 초기화 
	scanf_s("%d", &mins);
	for (int i = 0; i < mins; i++) {
		scanf_s("%d", &assignmentyn); // 과제 여부를 입력
		if (assignmentyn == 1) { // 과제가 있다면 
			scanf_s("%d %d", &score, &min);
			push(&s, score, min);// 점수, 시간을 push
			--(s.time[s.top]); // 과제를 부여받은 그 순간에도 과제를 할 수 있기 때문에 시간을 1 줄여야한다. 
			if (s.time[s.top] == 0) sum += pop(&s); //그 때 제 시간에 맞춰 과제를 끝냈다면 총 점수를 올린다. 
		}
		else if (assignmentyn == 0) { // 과제가 없다면
			--(s.time[s.top]); // 이때도 시간이 지나기 때문에 시간 1을 줄여야 한다.
			if (s.time[s.top] == 0) sum += pop(&s); //그 때 제 시간에 맞춰 과제를 끝냈다면 총 점수를 올린다.
		}

	}
	printf("%d\n", sum);
	return 0;
}