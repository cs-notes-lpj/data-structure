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

// 指定结点后插
bool InsertNextNode(LNode * ptr, int elem) {

  if (ptr == NULL) {
    printf("未指定任何结点，取消插入...\n");
    return false;
  }

  LNode * tmp = (LNode *)malloc(sizeof(LNode));
  if (tmp == NULL) {
    return false;
  }

  tmp->data = elem;
  tmp->next = ptr->next;
  ptr->next = tmp;

  return true;

}

// 按位序删结点
bool ListDelete(LinkList * list, int idx, int * res) {
  if (idx < 1) {
    printf("位序 「左」 非法，已取消本次删除\n");
    return false;
  }

  // 从头结点开始向后遍历寻找要删除结点的前驱结点；「将头结点看成位序 0」
  LNode * ptr = (*list); int index = 0;
  while (index + 1 < idx) {
    ptr = ptr->next;
    index++;

    if (ptr == NULL) {
      printf("位序 「右」 非法，已取消本次删除\n");
      return false;
    }
  }

  if (ptr->next == NULL) {
    printf("待删除位序的前驱结点是尾结点，已取消本次删除\n");
    return false;
  }

  LNode * deletedNode = ptr->next; // 缓存
  * res = deletedNode->data;       // 带回
  ptr->next = deletedNode->next;   // 调指向
  free(deletedNode);               // 释结点

  return true;
}

// 按位序查找结点
LNode * GetElemByIdx(LinkList list, int idx) {
  if (idx < 1) {
    printf("位序 「左」 非法，取消本次按位查找...\n");
    return NULL;
  }

  // 从位序 1 的结点开始向后遍历寻找位序为 idx 的结点
  LNode * ptr = list->next;
  int index = 1;

  while (index < idx) {
    ptr = ptr->next;
    index ++;

    if (ptr == NULL) {
      printf("位序 「右」 非法，取消本次按位查找...\n");
      return NULL;
    }
  }

  return ptr;

}

// 按值查找结点
// 注意：判断构造数据类型的数据元素之间的关系，不能用简单的等或不等号，而应封装一个加强版的判等函数来使用 ！
LNode * GetElemByData(LinkList list, int data) {

  // 链表判空（带头结点）
  LNode * ptr = list->next;
  if (list == NULL) {
    printf("你传进来的是个带头结点的空链表，取消本次按值查找...\n");
  }

  // 从位序 1 的结点逐个向后遍历查找值对应的结点
  while (ptr->data != data) {
    ptr = ptr->next;

    if (ptr == NULL) {
      printf("按值查找结点没找到...\n");
      return NULL;
    }
  }

  return ptr;

}

int Length(LinkList list) {
  if (list->next == NULL) {
    return 0;
  }

  int len = 0;
  for (LNode * ptr = list->next; ptr != NULL; ptr = ptr->next) {
    len++;
  }
  return len;
}

int main() {

  // 声明并初始化一个有头结点的单链表
  LinkList L = NULL;
  InitList(&L);

  // 有头结点的单链表的判空
  if (isEmpty(L)) {
    printf("恭喜，你声明并初始化了一个有头结点的空的单链表\n");
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

  // 期望：1001 1002 9999 1003
  printf("-------------\n");
  InsertNextNode(L->next->next, 9999);
  InsertNextNode(L->next->next->next->next->next, 1234);
  PrintList(L);

  // 删掉 9999 => 1001 1002 1003
  printf("-------------\n");
  int deletedData;
  if (ListDelete(&L, 3, &deletedData)) {
    printf("The deleted node contains number => %d\n", deletedData);
  };
  PrintList(L);

  // 输出链表的表长（头结点不存数据，不算入表长）
  printf("list-withHead-length: %d\n", Length(L));

  // 按位序查找结点 => 位序 2 => 1002
  LNode * resNode = GetElemByIdx(L, 2);
  if (resNode == NULL) {
    printf("按位序找结点没找到...\n");
  } else {
    printf("按位序找结点找到了，结点中存储的数据为：%d\n", resNode->data);
  }

  // 按值查找结点 => 1003
  int data = 1003;
  LNode * bakNode = GetElemByData(L, data);
  if (bakNode != NULL) {
    if (bakNode->data == data) {
      printf("按值查找结点找到了，结点中存储的数据确实为：%d\n", bakNode->data);
    } else {
      printf("按值查找结点找到了，但找到的结点中存储的数据和期望不对...\n");
    }
  }

  return 0;
}
