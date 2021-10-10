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

int main() {

  DLinkList L;
  if (InitDLinkList(&L)) {
    printf("恭喜，你声明并初始化了一个带头结点的空的双链表\n");
  }

  return 0;
}