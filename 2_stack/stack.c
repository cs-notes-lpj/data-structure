/**
 * 栈
*/

#include <stdio.h>

/* --- 定义栈 --- */
#define maxSize 10
typedef struct {
  int data[maxSize];
  int top;
} Stack;
/* --- 定义栈 --- */

// 初始化「栈」
typedef enum { false = 0, true } bool;
bool InitStack(Stack * s) {
  s->top = -1;  

  for (int i = 0; i < maxSize; i ++) {
    s->data[i] = 0;
  }

  return true;
}

int main() {

  Stack s;
  if (InitStack(&s)) {
    printf("恭喜，你成功初始化了一个空栈！\n");
  }

  return 0;
}
