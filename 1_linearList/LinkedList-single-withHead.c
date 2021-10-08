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

void PrintList(LinkList list) {
  LNode * ptr = list->next;
  while (ptr != NULL) {
    printf("%d\n", ptr->data);
    ptr = ptr->next;
  }
}

// 按位序插入
bool ListInsert(LinkList * L, int idx, int elem) {
  if (idx < 1) {
    printf("位序 %d 非法，取消本次插入...\n", idx);
    return false;
  }

  // 从头结点开始向后遍历寻找要插入位序的前一位，「将头结点的位序看作0」
  LNode * tmp = (*L); int index = 0;
  while (index + 1 < idx) {
    tmp = tmp->next; index ++;
    if (tmp == NULL) {
      printf("位序 %d 非法，取消本次插入...\n", idx);
      return false;
    }
  }

  LNode * newNode = (LNode *)malloc(sizeof(LNode));
  if (newNode == NULL) {
    return false;
  }

  // 插入结点
  newNode->data = elem;
  newNode->next = tmp->next;
  tmp->next = newNode;

  return true;

}

int main() {

  // 声明并初始化一个有头结点的单链表
  LinkList L = NULL;
  InitList(&L);

  // 有头结点的单链表的判空
  if (isEmpty(L)) {
    printf("恭喜，你声明并初始化了一个空的单链表\n");
    PrintList(L);
  }

  ListInsert(&L, 1, 1001);
  ListInsert(&L, 2, 1002);
  ListInsert(&L, 4, 1004);
  ListInsert(&L, 5, 1005);
  ListInsert(&L, -1, 777);
  ListInsert(&L, 3, 1003);

  // 期望：1001 1002 1003
  PrintList(L);

  return 0;
}
