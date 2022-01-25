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

// 入栈
bool Push(SeqStack* s, int elem) {

  // 栈满则拒绝入栈
  if (s->top == maxSize - 1) {
    return false;
  }
  
  // 入栈
  s->data[++(s->top)] = elem;
  return true;
}

// 从栈顶向栈底遍历输出栈
void printStack(SeqStack s) {
  // 栈空则直接返回
  if (s.top == -1) {
    return;
  }

  for (int i = s.top; i >= 0; i --) {
    printf("%d ", s.data[i]);
  }
  printf("\n");
  return;
}

// 出栈
bool Pop(SeqStack* s, int* res) {

  // 栈空则拒绝出栈
  if (s->top == -1) {
		return false;
  }
  
  // 出栈（只是将数据带回后调整栈顶指针，实际上数据还残留在内存中）
  (*res) = s->data[(s->top)--];
  return true;
}

// 读栈顶
bool GetTop(SeqStack s, int * res) {
  // 栈空，拒绝读栈顶
  if (s.top == -1) {
    return false;
  }

  (*res) = s.data[s.top];
  return true;
}

int main() {

  SeqStack s;
  if (InitSeqStack(&s) && isEmpty(s)) {
    printf("恭喜，你成功初始化了一个空的顺序栈！\n");
  }

  printf("顺序栈变量所占内存字节数：%d\n", sizeof(s)); // 44 => maxSize * sizeof(int) + sizeof(int)

  Push(&s, 111);
  Push(&s, 222);
  Push(&s, 333);
  printStack(s);

  int res;
  if (Pop(&s, &res)) {
    printf("出栈成功，res = %d\n", res);
    printStack(s);
  }

  int curTop;
  if (GetTop(s, &curTop)) {
    printf("当前栈顶数据元素为：%d\n", curTop);
  }

  return 0;
}
