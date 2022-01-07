/**
 * 循环单链表（带头结点）
*/

#include <stdio.h>
#include <stdlib.h>

struct NODE {
  int data;
  struct NODE * next;
};
typedef struct NODE CLNode;
typedef struct NODE * CLinkList;

// 初始化循环单链表
CLinkList InitList(CLinkList * list) {
  CLNode * tmp = (CLNode *)malloc(sizeof(CLNode));
  if (tmp == NULL) {
		return NULL;
  }
  
  tmp->next = tmp; // 循环单链表和普通单链表初始化的区别就在此
  (*list) = tmp;
  
  return (*list);
}

// 循环单链表判空
typedef enum { false = 0, true } bool;
bool isEmpty(CLinkList list) {
  return (list->next == list);
}

// 判断指针指向的是否是循环单链表的表尾结点
bool isTail(CLinkList L, CLNode * ptr) {
  if (L == NULL || ptr == NULL) {
    return false;
  }

  return (ptr->next == L);
}

int main() {

  CLinkList L = NULL;
  InitList(&L);

  if (isEmpty(L)) {
    printf("循环单链表为空\n");
  }

  return 0;
}