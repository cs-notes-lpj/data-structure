/**
 * 单链表( 无头结点 )
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

bool ListInsert(LinkList * list, int idx, int elem) {
  if (idx < 1) {
    printf("位序 %d 非法，取消本次插入...\n", idx);
    return false;
  }

  // 位序为 1 的结点无前驱结点，故需单独处理
  if (idx == 1) {

    LNode * node = (LNode *)malloc(sizeof(LNode));
    if (node == NULL) {
      return false;
    }

    node->data = elem;
    node->next = (*list);
    (*list) = node;

    return true;

  }

  // 从第一个结点开始向后遍历寻找待插入位序的前驱结点
  LNode * ptr = (*list); int index = 1;
  while (index + 1 < idx) {
    ptr = ptr->next;
    index++;

    if (ptr == NULL) {
      printf("位序 %d 非法，取消本次插入...\n", idx);
      return false;
    }
  }

  LNode * newNode = (LNode *)malloc(sizeof(LNode));
  if (newNode == NULL) {
    return false;
  }

  newNode->data = elem;
  newNode->next = ptr->next;
  ptr->next = newNode;

  return true;

}

// 指定结点前插
bool InsertPriorNode(LNode * ptr , int elem) {
  if (ptr == NULL) {
    printf("未指定任何结点，取消前插...\n");
    return false;
  }

  LNode * newNode = (LNode *)malloc(sizeof(LNode));
  if (newNode == NULL) {
    return false;
  }

  int tmpData = ptr->data;

  // 偷天换日（结点前插 == 结点后插 + 交换数据）
  newNode->next = ptr->next;
  ptr->next = newNode;

  ptr->data = elem;
  newNode->data = tmpData;

  return true;
}

bool DeleteNode(LNode * ptr, int * res) {
  if (ptr == NULL) {
    printf("指针指向 NULL，已取消本次删结点操作...");
    return false;
  }

  LNode * tmpPtr = ptr->next; // 缓存

  if (tmpPtr == NULL) {
    printf("指针指向尾结点，因尾结点无后继结点，故本方法不可用，已取消本次删结点操作...\n");
    return false;
  }

  ptr->next = ptr->next->next;// 调指向，构造出逻辑结构

  (*res) = ptr->data;         // 带回数据

  ptr->data = tmpPtr->data;   // 数据归位

  free(tmpPtr);               // 释结点内存

  return true;

}

int main() {

  LinkList L = NULL;
  if (isEmpty(L)) {
    printf("恭喜，你定义了一个无头结点的空的单链表\n");
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

  // 期望：123 1001 1002 1003
  printf("-------------\n");
  InsertPriorNode(L, 123);
  InsertPriorNode(L->next->next->next->next, 456);
  PrintList(L);

  // 期望：123 1002 1003
  printf("-------------\n");
  int deletedData;
  if (DeleteNode(L->next, &deletedData)) {
    printf("The deleted node contains number => %d\n", deletedData);
  };
  PrintList(L);

  return 0;
}
