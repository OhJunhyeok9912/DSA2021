#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 1000 // ���� ���ǿ��� N�� K�� 1000�����̹Ƿ� ũ�⸦ ������

typedef int element;  // �����ϴ� ���� �迭�� ����.
typedef struct {
    element data[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

void error(char* message) {  // ���� �Լ�
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init_queue(QueueType* q) {
    q->front = -1;
    q->rear = -1;
}

int is_empty(QueueType* q) {  // ���� ���� Ȯ�� �Լ�
    if (q->front == q->rear) {
        return 1;
    }
    else
        return 0;
}

int is_full(QueueType* q) { // ��ȭ ���� Ȯ�� �Լ�
    if (q->rear + 1 == MAX_QUEUE_SIZE)
        return 1;
    else
        return 0;
}

void enqueue(QueueType* q, element item) { // item �����Լ�
    if (is_full(q)) {
        error("ť�� ��ȭ�����Դϴ�.");
    }
    q->data[++(q->rear)] = item;
}

element dequeue(QueueType* q) {  // ���� �Լ�
    if (is_empty(q)) {
        error("ť�� ��������Դϴ�.");
    }
    int item = q->data[++(q->front)];
    return item;
}

void position(QueueType* q, element K) { // ���ڸ� ť���� K - 1 �� ��ŭ �ڷ� �����ϴ�. 
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

    for (int i = 1; i <= N; i++) {  // ó���� ť�� 1���� N���� ���� ����
        enqueue(&q, i);
    }
    for (int i = 0; i < N; i++) {  // position�Լ��� �־ ��ġ�� ������ �� ���� ������. 
        position(&q, K);
        enqueue(&result, dequeue(&q));
    }
    for (int i = 0; i < N; i++) {  // ����� ����Ʈ 
        printf("%d ", dequeue(&result));
    }
    return 0;
}