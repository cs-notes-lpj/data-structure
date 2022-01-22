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

bool isEmpty(DLinkList list) {
  if (list == NULL) {
    printf("你传进来的是个 NULL 而并非一个带头结点的双链表，已取消本次判空操作\n");
    return true;
  }
  return (list->next == NULL);
}

// 遍历输出双链表
void printDLinkList(DLinkList list) {

  if (list == NULL || list->next == NULL) {
    return;
  }

  for (DNode* ptr = list->next; ptr != NULL; ptr = ptr->next) {
    printf("%d ", ptr->data);
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
  destPtr->next = newNode;
  newNode->prior = destPtr;
  if (newNode->next != NULL) {
    newNode->next->prior = newNode;
  }
  return true;
}

// 指定结点删除
bool DeleteNode(DNode* ptr) {
  if (ptr == NULL) {
    return false;
  }

  if (ptr->prior == NULL) {
    printf("不允许删除双链表的头结点，已取消本次删除结点的操作\n");
    return false;
  }

  DNode* priorPtr = ptr->prior;
  priorPtr->next = ptr->next;
  if (ptr->next != NULL) {
    ptr->next->prior = priorPtr;
  }

  free(ptr);
  return true;
}

bool DestoryDLinkList(DLinkList* list) {
  if ((*list) == NULL) {
    printf("你传进来的是个 NULL 而并非一个带头结点的双链表，已取消本次销毁操作\n");
    return true;
  }

  if ((*list)->prior != NULL) {
    printf("得保证传进来的指针指向头结点，才能将双链表完全销毁\n");
    return false;
  }

  // 每次都是销毁头结点的后继结点
  while ((*list)->next != NULL) {
    DeleteNode((*list)->next);
  }

  // 销毁头结点
  free(*list);
  // 处理野指针
  (*list) = NULL;

  return true;
}

int main() {

  DLinkList L = NULL;
  if (InitDLinkList(&L) && isEmpty(L)) {
    printf("恭喜，你声明并初始化了一个带头结点的空的双链表\n");
  }

  // 指定结点的后插操作
  InsertNextNode(L, 100);
  InsertNextNode(L, 200);
  InsertNextNode(L->next, 999);
  InsertNextNode(L, 300);
  InsertNextNode(L, 400);

  printDLinkList(L); // 400 300 200 999 100

  // 指定节点删除
  DeleteNode(L->next->next->next->next);
  printDLinkList(L); // 400 300 200 100

  // 销毁链表
  if (DestoryDLinkList(&L)) {
    printf("链表销毁成功\n");
  }
  printDLinkList(L);
  return 0;
}