#include <stdio.h>
#include <stdlib.h>
#define MAX 100000

typedef int element; // 정수형 숫자를 대상으로 하기 때문에 typedef로 element 타입을 만든다.
typedef struct {
	element data[MAX]; // data를 저장할 배열을 element 타입으로 생성
	int top; // 스택의 top을 가리킬 변수를 생성
}Stack; // 스택을 구조체로 정의해서 사용한다.

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
	int sum = 0; // 합을 0으로 초기화한다.
	Stack s; init_stack(&s); // 스택을 정적으로 생성 후, 초기화 한다. 
	scanf_s("%d", &k); // 몇 번 입력해야 하는지 k값을 입력 
	for (int i = 0; i < k; i++) { // 입력 받은 k 만큼 반복
		scanf_s("%d", &num); // 관리해야 할 돈들을 입력
		if (num == 0) pop(&s); // 0일 때 최근에 쓴 수를 지우기 때문에 pop연산으로 스택의 top에 있는 숫자를 꺼낸다
		else push(&s, num); // 그 외의 숫자일 때 push연산으로 스택에 넣는다.
	}
	for (int i = s.top; i >= 0; i--) { // 돈의 입력이 끝나면 스택에 남아있는 요소만큼 반복(스택의 top을 기준으로 data의 배열 첫 인덱스까지 반복)
		sum += pop(&s); // sum에 스택의 배열에 있는 top부터 처음까지 반환해서 더한다.
	}
	printf("\n%d\n", sum); // sum을 출력
	return 0;
}
