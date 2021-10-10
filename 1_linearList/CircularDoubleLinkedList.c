/**
 * 循环双链表（带头结点）
*/

#include <stdio.h>
#include <stdlib.h>

/* --------- 定义循环双链表 --------- */
struct NODE {
  int data;
  struct NODE * next;
  struct NODE * prior;
};

typedef struct NODE CDNode;
typedef struct NODE * CDList;
/* --------- 定义循环双链表 --------- */

// 初始化一个带头结点的循环双链表
CDList InitCDList(CDList * list) {
  CDNode * tmp = (CDNode *)malloc(sizeof(CDNode));
  if (tmp == NULL) {
    return NULL;
  }

  tmp->next = tmp;
  tmp->prior = tmp;
  (*list) = tmp;

  return (*list);
}

int main() {

  // 声明并初始化一个带头结点的循环双链表
  CDList L;
  InitCDList(&L);

  return 0;
}
