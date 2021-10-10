/**
 * 双链表（带头结点）
*/

#include <stdio.h>
#include <stdlib.h>

/* --------- 定义双链表 --------- */
struct NODE {
  int data;
  struct NODE * next;
  struct NODE * prior;
};

typedef struct NODE DNode;
typedef struct NODE * DLinkList;
/* --------- 定义双链表 --------- */

// 初始化双链表（带头结点）
typedef enum { false = 0, true } bool;
bool InitDLinkList(DLinkList * list) {
  DNode * headNode = (DNode *)malloc(sizeof(DNode));
  if (headNode == NULL) {
    return false;
  }

  headNode->next = NULL;
  headNode->prior = NULL;

  (*list) = headNode;
  return true;

}

/**
 * 返回 true：说明你传进来的带头结点的双链表为 「空」
 * 返回 false：说明你传进来的带头结点的双链表为 「不空」 或你传进来的就不是个带头结点的双链表
*/
bool isEmpty(DLinkList list) {
  if (list == NULL) {
    printf("你传进来的就不是个带头结点的双链表，你传进来的是个 NULL，已取消本次判空操作\n");
    return false;
  }
  return (list->next == NULL);
}

// 遍历输出双链表
void printDLinkList(DLinkList list) {
  if (list == NULL) {
    return;
  }

  DNode * ptr = list->next;

  while (ptr != NULL) {
    printf("%d ", ptr->data);
    ptr = ptr->next;
  }

  printf("\n");
  return;
}

/** 指定结点的后插操作
 * destPtr 被插结点，将在该结点后插入新结点
 * data 新结点中将存放的数据元素
*/
bool InsertNextNode(DNode * destPtr, int data) {
  if (destPtr == NULL) {
    return false;
  }

  DNode * newNode = (DNode *)malloc(sizeof(DNode));
  if (newNode == NULL) {
    return false;
  }
  newNode->data = data;

  newNode->next = destPtr->next;
  if (destPtr->next != NULL) {
    destPtr->next->prior = newNode;
  }
  destPtr->next = newNode;
  newNode->prior = destPtr;

  return true;

}

int main() {

  DLinkList L;
  if (InitDLinkList(&L) && isEmpty(L)) {
    printf("恭喜，你声明并初始化了一个带头结点的空的双链表\n");
  }

  // 指定结点的后插操作
  InsertNextNode(L, 100);
  printDLinkList(L);

  return 0;
}