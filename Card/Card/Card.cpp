#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 500001
typedef int element;
typedef struct QueueType {
    element  data[MAX_QUEUE_SIZE];
    int  front, rear;
} QueueType​;

void init_queue(QueueType* q) {
    q->front = q->rear = 0;
}
int is_empty(QueueType* q) {
    return (q->front == q->rear);
}

int is_full(QueueType* q) {
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void enqueue(QueueType* q, element item) {
    if (is_full(q)) return;
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

element dequeue(QueueType* q)
{
    if (is_empty(q)) exit(1);
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

void last_card(QueueType* q) {
    while (q->front + 1 != q->rear) { // 원형큐에서 데이터가 하나만 있다는 것은 front와 rear의 차이가 1이라는 것이다. 그러면 1이 아닐 때까지는 과정을 반복해야한다. 
        dequeue(q); // 첫 카드는 먼저 뺀다.
        enqueue(q, dequeue(q)); // 그 다음은 뒤로 옮겨야 하므로 카드를 빼고 바로 큐에 다시 삽입한다. 
    }
    printf("%d\n", q->data[q->rear]);
}

int main() {
    QueueType queue;
    init_queue(&queue);
    int cardnum;
    scanf_s("%d", &cardnum);
    for (element i = 1; i <= cardnum; i++) {
        enqueue(&queue, i); // 1부터 사용자가 입력한 카드 수만큼 큐에 삽입한다. 
    }
    last_card(&queue); // 마지막 카드를 알기 위해 큐를 매개변수로 한다. 
    return 0;
}