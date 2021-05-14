#include <stdio.h>
#include <stdlib.h>

typedef struct { // 넣을 정보는 이름, 나이, 키 구조체로 저장
    char* Name;
    int Age;
    double Height;
}information;

typedef struct ListNode {
    information data;
    struct ListNode* link;
} ListNode;

ListNode* insert(ListNode* head, information value) { // 노드의 첫 번째에 삽입하는 함수
    ListNode* p = (ListNode*)malloc(sizeof(ListNode)); // 새로운 노드 생성
    p->data = value;   // 넣은 값을 저장
    p->link = head;    // 현재의 헤드값 저장
    head = p;    // 헤드 포인터 변경
    return head;   // 현재 헤드 반환
}

void print_list(ListNode* head) {    // 노드의 데이터 출력
    for (ListNode* p = head; p != NULL; p = p->link) {  //Null이 나올 때 즉 끝날 때까지 출력
        printf("Name: %s Age: %d Height: %.1f\n", p->data.Name, p->data.Age, p->data.Height);  // 이름, 나이, 키 출력
    }
}

int main(void) {
    ListNode* head = NULL;
    information data;

    data.Name = "choi"; data.Age = 30; data.Height = 1.3; // 데이터 저장하기
    head = insert(head, data);
    data.Name = "lee"; data.Age = 48; data.Height = 1.4;
    head = insert(head, data);
    data.Name = "park"; data.Age = 27; data.Height = 1.2;
    head = insert(head, data);
    data.Name = "kim"; data.Age = 34; data.Height = 1.7;
    head = insert(head, data);
    print_list(head);
}

