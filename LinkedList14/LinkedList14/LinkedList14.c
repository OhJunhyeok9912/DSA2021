#include <stdio.h>
#include <stdlib.h>

typedef struct { // ���� ������ �̸�, ����, Ű ����ü�� ����
    char* Name;
    int Age;
    double Height;
}information;

typedef struct ListNode {
    information data;
    struct ListNode* link;
} ListNode;

ListNode* insert(ListNode* head, information value) { // ����� ù ��°�� �����ϴ� �Լ�
    ListNode* p = (ListNode*)malloc(sizeof(ListNode)); // ���ο� ��� ����
    p->data = value;   // ���� ���� ����
    p->link = head;    // ������ ��尪 ����
    head = p;    // ��� ������ ����
    return head;   // ���� ��� ��ȯ
}

void print_list(ListNode* head) {    // ����� ������ ���
    for (ListNode* p = head; p != NULL; p = p->link) {  //Null�� ���� �� �� ���� ������ ���
        printf("Name: %s Age: %d Height: %.1f\n", p->data.Name, p->data.Age, p->data.Height);  // �̸�, ����, Ű ���
    }
}

int main(void) {
    ListNode* head = NULL;
    information data;

    data.Name = "choi"; data.Age = 30; data.Height = 1.3; // ������ �����ϱ�
    head = insert(head, data);
    data.Name = "lee"; data.Age = 48; data.Height = 1.4;
    head = insert(head, data);
    data.Name = "park"; data.Age = 27; data.Height = 1.2;
    head = insert(head, data);
    data.Name = "kim"; data.Age = 34; data.Height = 1.7;
    head = insert(head, data);
    print_list(head);
}

