/**
 * 单链表( 有头结点 )
*/

#include <stdio.h>
#include <stdlib.h>

/* --------- 定义单链表 --------- */
struct NODE {
  int data;
  struct NODE * next;
};

typedef struct NODE LNode;
typedef LNode * LinkList;
/* --------- 定义单链表 --------- */

LinkList InitList(LinkList * list) {

  LNode * tmp = (LNode *)malloc(sizeof(LNode));
  if (tmp == NULL) {
    return tmp;
  }

  tmp->next = NULL;

  (*list) = tmp;
  return (*list);

}

typedef enum { false = 0, true } bool;
bool isEmpty(LinkList L) {
  if (L->next == NULL) {
    return true;
  }
}

int main() {

  // 声明并初始化一个有头结点的单链表
  LinkList L = NULL;
  InitList(&L);

  // 有头结点的单链表的判空
  if (isEmpty(L)) {
    printf("恭喜，你声明并初始化了一个空的单链表\n");
  }

  return 0;
}
