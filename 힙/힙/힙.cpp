#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 100000

typedef struct {
    int key;
}element;

typedef struct {
    element heap[MAX_ELEMENT];
    int heap_size;
} HeapType;

HeapType* create() { // 생성함수
    return (HeapType*)malloc(sizeof(HeapType));
}

void init(HeapType* h) { // 초기화 함수
    h->heap_size = 0;
}

int size(HeapType* h) { // 크기 함수 
    return h->heap_size;
}

void insert_max_heap(HeapType* h, element item) { // 현재 요소의 개수가 heap_size인 히프h에 item 삽입
    int i;
    i = ++(h->heap_size);

    //트리를 거슬러 올라가면서 부모 노드와 비교하는 과정
    while ((i != 1) && (item.key > h->heap[i / 2].key)) {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }
    //새로운 노드를 삽입
    h->heap[i] = item;
}

// 삭제 함수
element delete_max_heap(HeapType* h) {
    int parent, child;
    element item, temp;

    item = h->heap[1];
    temp = h->heap[(h->heap_size)--];
    parent = 1;
    child = 2;
    while (child <= h->heap_size) {
        //현재 노드를 자식 노드 중 더 큰 자식노드를 찾느다. 
        if ((child < h->heap_size) && (h->heap[child].key) < h->heap[child + 1].key)
            child++;
        if (temp.key >= h->heap[child].key)
            break;
        // 한단계 아래로 이동
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp;
    return item;
}

int main(void) {
    HeapType* heap;

    heap = create(); // 히프 생성
    init(heap);      // 초기화

    int num;
    scanf("%d", &num);
    for (int i = 0; i < num; i++) {
        element e;
        scanf("%d", &e.key);
        if (e.key == 0) { // 0을 입력했을 때
            if (heap->heap_size == 0) { //힙이 비어있다면 0을 출력
                printf("%d\n", 0);
            }
            else {
                element out = delete_max_heap(heap);// 비어있지 않다면 가장 큰 값을 출력
                printf("%d\n", out);
            }
        }
        else {
            insert_max_heap(heap, e); // 0이 아니라면 힙에 삽입
        }
    }

    free(heap);
    return 0;
}