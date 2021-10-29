/**
 * 中缀表达式 => 后缀表达式（逆波兰式）
 * 为确保算法的确定性 & 使先生效的运算符先出现
 * 采用所谓 => 「运算符优先级相等则左优先的原则」
 */

#include <stdio.h>
typedef enum { false = 0, true } bool;

/*-- 简单实现个顺序栈 --*/
#define maxSize 27
typedef struct {
  char arr[maxSize];
  int top;
} Stack;

// 初始化栈
bool InitStack(Stack * s) {
  s->top = -1;

  for (int i = 0; i < maxSize; i ++) {
    s->arr[i] = 0;
  }

  return true;
}

// 压栈
bool Push(Stack * s, int newElem) {
  if (s->top == maxSize - 1) {
    printf("栈满，拒绝入栈...\n");
    return false;
  }

  s->arr[s->top + 1] = newElem;
  s->top = s->top + 1;
  return true;
}

// 出栈
bool Pop(Stack * s, char * res) {
  if (s->top == -1) {
    printf("栈空，拒绝出栈...\n");
    return false;
  }

  (*res) = s->arr[s->top];
  // 逻辑上的出栈，实际上数据元素还残留在内存中
  s->top = s->top - 1;
  return true;
}

// 判栈空
bool IsEmpty(Stack s) {
  return s.top == -1;
}
/*-- 简单实现个顺序栈 --*/



int main() {

  printf("请输入一个整数，表示您希望输入一个多长的中缀表达式，按回车确认：");
  const int len;
  scanf("%d", &len);

  printf("请输入一个长度为 %d 的中缀表达式，按回车确认：", len);

  // 注意啊！这里是 len + 1，因为字符数组最后一个位置得留给'\0'
  #define arrSize len + 1
  char NN[arrSize];
  for (int i = 0; i < arrSize; i ++) {
    scanf("%c", &NN[i]);
  }

  printf("您输入的中缀表达式为：%s\n", NN);

  // // 中缀表达式
  // char NN[27] = { '(', '(', 15, '/', '(', 7, '-', '(', 1, '+', 1, ')', ')', ')', '*', 3, ')', '-', '(', 2, '+', '(', 1, '+', 1, ')', ')' };

  return 0;
}