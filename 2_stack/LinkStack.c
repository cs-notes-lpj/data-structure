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
  return;
}

int main() {

  // 声明一个链栈（无头结点）
  LinkStack s = NULL;

  Push(&s, 111);
  Push(&s, 222);
  Push(&s, 333);
  PrintLinkStack(s); // stack => LIFO => 333 222 111

  return 0;
}