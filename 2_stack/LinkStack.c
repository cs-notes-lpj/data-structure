/**
 * 链栈 <= 单链表 + 只允许在一端进行插入删除操作
*/

#include <stdio.h>
#include <stdlib.h>

/* --- 定义数据类型：链栈的结点 --- */
struct NODE {
  int data;
  struct NODE * next;
};

typedef struct NODE LSNode;
typedef struct NODE * LinkStack;
/* --- 定义数据类型：链栈的结点 --- */

typedef enum { false = 0, true } bool;
bool Push(LinkStack * s, int elem) {
  LSNode * tmp = (LSNode *)malloc(sizeof(LSNode));
  if (tmp == NULL) {
    return false;
  }

  tmp->data = elem;
  tmp->next = *s;
  (*s) = tmp;
  return true;

}

void PrintLinkStack(LinkStack s) {
  if (s == NULL) {
    return;
  }

  LSNode * ptr = s;
  while (ptr != NULL) {
    printf("%d ", ptr->data);
    ptr = ptr->next;
  }
  printf("\n");
  return;
}

bool Pop(LinkStack * s, int * res) {
  // 栈空则拒绝出栈
  if ((*s) == NULL) {
    return false;
  }

  LSNode * tmp = (*s); // 缓存待出栈结点

  /* --- 出栈 --- */
  (*s) = (*s)->next;
  (*res) = tmp->data;
  free(tmp);
  /* --- 出栈 --- */

  return true;

}

// 读栈顶
bool GetTop(LinkStack s, int * res) {
  // 栈空，则拒绝读栈
  if (s == NULL) {
    return false;
  }

  (*res) = s->data;
  return true;
}

int main() {

  // 声明一个链栈（无头结点）
  LinkStack s = NULL;

  Push(&s, 111);
  Push(&s, 222);
  Push(&s, 333);
  PrintLinkStack(s); // stack => LIFO => 333 222 111

  int res;
  if (Pop(&s, &res)) {
    PrintLinkStack(s); // 222 111
    printf("出栈的结点元素：%d\n", res);
  }

  int curTop;
  if (GetTop(s, &curTop)) {
    printf("读栈顶成功，当前栈顶元素为：%d\n", curTop);
  }

  return 0;
}