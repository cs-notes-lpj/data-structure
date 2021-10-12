/**
 * 顺序栈
*/

#include <stdio.h>

/* --- 定义顺序栈 --- */
#define maxSize 10
typedef struct {
  int data[maxSize];
  int top;
} SeqStack;
/* --- 定义顺序栈 --- */

// 顺序栈的初始化
typedef enum { false = 0, true } bool;
bool InitSeqStack(SeqStack * s) {
  s->top = -1;  

  for (int i = 0; i < maxSize; i ++) {
    s->data[i] = 0;
  }

  return true;
}

// 顺序栈判空
bool isEmpty(SeqStack s) {
  return (s.top == -1);
}

int main() {

  SeqStack s;
  if (InitSeqStack(&s) && isEmpty(s)) {
    printf("恭喜，你成功初始化了一个空的顺序栈！\n");
  }

  printf("顺序栈变量所占内存字节数：%d\n", sizeof(s)); // 44 => maxSize * sizeof(int) + sizeof(int)



  return 0;
}
