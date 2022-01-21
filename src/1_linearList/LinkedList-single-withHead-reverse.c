/**
 * 建立一个有头结点的单链表，原地逆置它！
*/

#include <stdio.h>
#include <stdlib.h>

/* --------- 定义单链表 --------- */
struct NODE {
  int data;
  struct NODE * next;
};

typedef struct NODE LNode;
typedef struct NODE * LinkList;
/* --------- 定义单链表 --------- */

// utils
void _printListWithHead(LinkList list);

// 初始化单链表（带头结点）
LinkList InitList(LinkList* list) {
  LNode* tmp = (LNode*)malloc(sizeof(LNode));
  if (tmp == NULL) {
    printf("创建头结点失败...\n");
    return NULL;
  }

  (*list) = tmp;
  tmp->next = NULL;
  return (*list);
}

// 建立带头结点的单链表（尾插法）
LinkList creatListInsertTail(LinkList* list, int data[], int length) {
  if (length < 1) {
    return (*list);
  }

  // 用于记录尾结点
  LNode* tail = (*list);

  for (int i = 0; i < length; i ++) {
    LNode* tmp = (LNode*)malloc(sizeof(LNode));
    if (tmp == NULL) {
      return (*list);
    }

    tmp->data = data[i];
    tmp->next = tail->next;
    tail->next = tmp;
    tail = tail->next; // 更新尾结点
  }

  return (*list);
}

// 原地逆序带头结点的单链表（头插法）
LinkList reverseList(LinkList* list) {
  if (*list == NULL) {
    printf("逆序单链表失败，你传进来的是个 NULL...\n");
    return (*list);
  }

  if ((*list)->next == NULL) {
    printf("无需逆序单链表，你传进来的是个带头结点的空的单链表...\n");
    return (*list);
  }

  if ((*list)->next->next == NULL) {
    printf("无需逆序单链表，你传进来的是个表长为 1 的带头结点的单链表：");
    return (*list);
  }

  LNode* ptr = (*list)->next;
  for (LNode* ptrNext = ptr->next; ptrNext != NULL; ptrNext = ptr->next) {
    ptr->next = ptrNext->next;     // 断前
    ptrNext->next = (*list)->next; // 断后
    (*list)->next = ptrNext;       // 调整头结点的 next 指向
  }

  return (*list);
}

int main () {

  // 声明并初始化一个带头结点的单链表
  LinkList L = NULL; InitList(&L);

  /* ---- 建立带头结点的单链表 ---- */
  printf("请输入一个正整数，表示接下来你想往空的带头结点的单链表中插入几个结点：");
  int num = 0;
  scanf("%d", &num);

  printf("你现在可以输入 %d 个整数，每输入一个整数，就按一次回车,表示每一个结点中存放的数据\n", num);
  int len = num, arr[len];
  for (int i = 0; i < num; i ++) {
    scanf("%d", &arr[i]);
  }

  L = creatListInsertTail(&L, arr, len);
  printf("恭喜！你创建了一个带头结点的单链表：");
  _printListWithHead(L);
  /* ---- 建立带头结点的单链表 ---- */

  printf("原地逆序该链表，结果如下...\n");
  _printListWithHead(reverseList(&L));

  return 0;
}

/*-- Utils are under below. --*/

// 打印带头结点的单链表
void _printListWithHead(LinkList list) {
  for (LNode* ptr = list->next; ptr != NULL; ptr = ptr->next) {
    printf("%d ", ptr->data);
  }
  printf("\n");
}
