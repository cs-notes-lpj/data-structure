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

typedef enum { false = 0, true } bool;
bool isEmpty(CDList list) {
  return (list->next == list);
}

// 判断 ptr 所指向结点是否是 list 的尾结点
bool isTail(CDList list, CDNode * ptr) {
  if (list == NULL || ptr == NULL) {
    return false;
  }
  return (ptr->next == list);
}

int main() {

  // 声明并初始化一个带头结点的循环双链表
  CDList L;
  InitCDList(&L);

  if (isEmpty(L)) {
    printf("你成功初始化了一个带头结点的空的循环双链表\n");
  }

  return 0;
}
