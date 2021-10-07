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

int main() {

  LinkList L = NULL;
  if (isEmpty(L)) {
    printf("恭喜，你定义了一个空的单链表\n");
  }

  return 0;
}
