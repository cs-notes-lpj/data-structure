/**
 * 计算后缀表达式
 * 注：由中缀表达式使用“运算符左优先原则”转换而来
 */

#include <stdio.h>
typedef enum { false = 0, true } bool;

/* --- 简单实现一个顺序栈，封装一点基本操作 --- */
#define maxSize 20
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

// 入栈
bool Push(Stack * s, int num) {
  // 栈满，则拒绝入栈
  if (s->top == maxSize - 1) {
    printf("栈满，拒绝入栈...\n");
    return false;
  }

  s->arr[s->top + 1] = num;
  s->top = s->top + 1;
  return true;
}

// 出栈
bool Pop(Stack * s, int * res) {
  // 栈空则拒绝出栈
  if (s->top == -1) {
    return false;
  }

  // 逻辑上的出栈，实际上数据还残留在内存中
  (*res) = s->arr[s->top];
  s->top = s->top - 1;
  return true;
}
/* --- 简单实现一个顺序栈，封装一点基本操作 --- */

/* --- tools --- */
// 判断是否是操作符
bool isOperator(char c) {
  switch (c) {
    case '+':
    case '-':
    case '*':
    case '/':
      return true;
    default:
      return false;
  }
}

// 不是操作符（本程序将不是操作符的直接当作了操作数，其实不严谨）
bool NotOperator(char c) {
  return !isOperator(c);
}

// 代码写得不健壮啊！（偷懒，逃。。。）
int count(int left, int right, char operator) {
  switch (operator) {
    case '+':
      return (left + right);
    case '-':
      return (left - right);
    case '*':
      return (left * right);
    case '/':
      return (left / right);
    default:
      return -99999;
  }
}
/* --- tools --- */


// 计算后缀表达式
int countRPN(char rpn[], int len) {

  Stack s;
  if (InitStack(&s)) {

    // 从左向右遍历后缀表达式，遇到操作数则入栈，遇到操作符则弹栈两次，然后进行运算，将运算结果压栈，直至遍历结束
    for (int i = 0; i < len; i ++) {

      char curElem = rpn[i];

      if (NotOperator(curElem)) {
        Push(&s, curElem);
        continue;
      }

      // 这里没对 Pop 是否成功做校验啊（偷懒，逃。。。）
      int right, left;
      Pop(&s, &right); Pop(&s, &left);

      // 测试代码（打印计算步骤）
      printf("%d %c %d\n", left, curElem, right);

      // 代码不健壮啊（偷懒，逃。。。）
      Push(&s, count(left, right, curElem));

    }

    // 如果栈中只剩一个节点，则后缀表达式合法，返回运算结果；否则说明后缀表达式非法，这里规定返回 -1
    return s.top == 0 ? s.arr[0] : -1;

  } else {
    printf("栈初始化失败...\n");
  }

}

int main() {
  // 后缀表达式
  char RPN[15] = { 15, 7, 1, 1, '+', '-', '/', 3, '*', 2, 1, 1, '+', '+', '-' };

  // 测试代码
  printf("计算步骤如下：\n");

  int res = countRPN(RPN, sizeof(RPN) / sizeof(char));

  printf("计算结果：%d\n", res);

  return 0;
}
