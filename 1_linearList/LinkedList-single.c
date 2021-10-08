/**
 * 单链表( 无头结点 )
*/

#include <stdio.h>

/* --------- 定义单链表 --------- */
struct NODE {
  int data;
  struct NODE * next;
};

typedef struct NODE LNode;
typedef LNode * LinkList;
/* --------- 定义单链表 --------- */

typedef enum { false = 0, true } bool;
bool isEmpty(LinkList L) {
  return L == NULL;
}

void PrintList(LinkList list) {
  LNode * ptr = list;
  while (ptr != NULL) {
    printf("%d\n", ptr->data);
    ptr = ptr->next;
  }
}

int main() {

  LinkList L = NULL;
  if (isEmpty(L)) {
    printf("恭喜，你定义了一个无头结点的空的单链表\n");
    PrintList(L);
  }

  // ListInsert(&L, 1, 1001);
  // ListInsert(&L, 2, 1002);
  // ListInsert(&L, 4, 1004);
  // ListInsert(&L, 5, 1005);
  // ListInsert(&L, -1, 777);
  // ListInsert(&L, 3, 1003);

  // // 期望：1001 1002 1003
  // PrintList(L);

  return 0;
}
