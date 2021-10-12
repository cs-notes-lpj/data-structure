/**
 * 共享栈
*/

#include <stdio.h>

/* --- 定义共享栈 --- */
#define maxSize 20
typedef struct {
  int data[maxSize];
  int top0;
  int top1;
} ShStack;
/* --- 定义共享栈 --- */

typedef enum { false = 0, true } bool;
// 初始化共享栈
bool InitShStack (ShStack * s) {
  s->top0 = -1;
  s->top1 = maxSize;

  // 擦洗内存脏数据
  for (int i = 0; i < maxSize; i ++) {
    s->data[i] = 0;
  }
  return true;
}

int main() {

  ShStack s;
  if (InitShStack(&s)) {
    printf("恭喜，你成功初始化了一个空的共享栈！\n");
  }

  return 0;
}