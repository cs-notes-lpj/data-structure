/**
 * 原地反转单链表
 */

#include <stdio.h>

/*--定义单链表--*/
struct Node {
  int data;
  struct Node* next;
};
typedef struct Node Node;
typedef struct Node* LinkList;
/*--定义单链表--*/

void printLinkedList(LinkList list) {
  while (list != NULL) {
    printf("%d ", list->data);
    list = list->next;
  }
  printf("\n");
}

LinkList reverseList(LinkList* list) {
  if (*list == NULL || (*list)->next == NULL) {
    return *list;
  }

  Node* pre = NULL;
  Node* cur = *list;

  while (cur) {
    Node* tmp = cur->next;
    cur->next = pre;

    pre = cur;
    cur = tmp;
  }

  return pre;
}

int main() {
  Node a, b, c, d, e;
  a.data = 1; b.data = 2; c.data = 3; d.data = 4; e.data = 5;
  a.next = &b; b.next = &c; c.next = &d; d.next = &e; e.next = NULL;

  LinkList list = &a;
  printLinkedList(list);

  LinkList reversedList = reverseList(&list);
  printLinkedList(reversedList);

  return 0;
}
