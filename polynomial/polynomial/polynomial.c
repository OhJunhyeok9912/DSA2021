#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct ListNode { // 노드 타입
    int coef;  //계수
    int expon;   // 차수
    struct ListNode* link;
} ListNode;

// 연결 리스트 헤더
typedef struct ListType { // 리스트 헤더 타입 
    int size;
    ListNode* head;
    ListNode* tail;
} ListType;


//오류 함수
void error(char* message) {
    fprintf(stderr, "%s\n", message);
}

//리스트 헤더 생성 함수
ListType* create() {
    ListType* plist = (ListType*)malloc(sizeof(ListType));
    plist->size = 0;
    plist->head = plist->tail = NULL;
    return plist;
}

//plist는 연결 리스트의 헤더를 가리키는 포인터
void insert_last(ListType* plist, int coef, int expon) {
    ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
    if (temp == NULL) {
        error("메모리 할당 에러");
    }
    temp->coef = coef;
    temp->expon = expon;
    temp->link = NULL;
    if (plist->tail == NULL) {
        plist->head = plist->tail = temp;
    }
    else {
        plist->tail->link = temp;
        plist->tail = temp;
    }
    plist->size++;
}


// 다항식을 계산하는 함수
void calculator(ListType* plist, int x) {
    ListNode* p = plist->head;
    int result = 0;
    for (; p; p = p->link) {
        result = result + p->coef * pow(x, p->expon);
    }
    printf("%d\n", result);
}

int main(void) {
    ListType* list1;

    list1 = create();

    // 다항식 하나를 생성
    insert_last(list1, 1, 3);
    insert_last(list1, 2, 1);
    insert_last(list1, 6, 0);
    int x;
    scanf("%d", &x);
    // 다항식 계산
    calculator(list1, x);
}