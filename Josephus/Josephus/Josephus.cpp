#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 1000 // 문제 조건에서 N과 K는 1000이하이므로 크기를 선언함

typedef int element;  // 저장하는 곳을 배열로 만듦.
typedef struct {
    element data[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

void error(char* message) {  // 오류 함수
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init_queue(QueueType* q) {
    q->front = -1;
    q->rear = -1;
}

int is_empty(QueueType* q) {  // 공백 상태 확인 함수
    if (q->front == q->rear) {
        return 1;
    }
    else
        return 0;
}

int is_full(QueueType* q) { // 포화 상태 확인 함수
    if (q->rear + 1 == MAX_QUEUE_SIZE)
        return 1;
    else
        return 0;
}

void enqueue(QueueType* q, element item) { // item 삽입함수
    if (is_full(q)) {
        error("큐가 포화상태입니다.");
    }
    q->data[++(q->rear)] = item;
}

element dequeue(QueueType* q) {  // 삭제 함수
    if (is_empty(q)) {
        error("큐가 공백상태입니다.");
    }
    int item = q->data[++(q->front)];
    return item;
}

void position(QueueType* q, element K) { // 숫자를 큐에서 K - 1 개 만큼 뒤로 보냅니다. 
    for (int i = 0; i < K - 1; i++) {
        int item = dequeue(q);
        enqueue(q, item);
    }
}


int main(void) {
    QueueType q;
    init_queue(&q);
    QueueType result;
    init_queue(&result);
    int N = 0;
    int K = 0;
    scanf("%d", &N);
    scanf("%d", &K);

    for (int i = 1; i <= N; i++) {  // 처음에 큐에 1부터 N까지 숫자 저장
        enqueue(&q, i);
    }
    for (int i = 0; i < N; i++) {  // position함수에 넣어서 위치를 조정한 후 값을 꺼내옴. 
        position(&q, K);
        enqueue(&result, dequeue(&q));
    }
    for (int i = 0; i < N; i++) {  // 결과를 프린트 
        printf("%d ", dequeue(&result));
    }
    return 0;
}