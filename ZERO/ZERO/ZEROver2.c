#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 1000000 // 스택의 최대 크기
#define _CRT_SECURE_NO_WARNINGS

typedef int element; //데이터의 자료형
element stack[MAX_STACK_SIZE]; // 1차원 배열로 스택을 만듦
int top = -1;

//삽입함수
void push(element item) {
	stack[++top] = item;
}

//삭제함수
void pop() {
	stack[top--] = 0;
}

int main(void) {

	int num = 0;
	int num1 = 0;
	int Sum = 0;
	scanf_s("%d", &num);

	for (int i = 0; i < num; i++) {
		scanf_s("%d", &num1); // 반복하고 싶은 횟수 받기
		if (num1 == 0) { // 0일 경우 pop함수를 이용하여 삭제
			pop();
		}
		else {
			push(num1); //0이 아닌 다른 숫자일 경우 스택에 삽입
		}
	}
	for (int i = 0; i < top + 1; i++) {
		Sum += stack[i]; // 반복문 실행 결과 후 스택에 있는 값 모두 Sum에 합치기
	}
	printf("%d", Sum); // 합계 출력
}

