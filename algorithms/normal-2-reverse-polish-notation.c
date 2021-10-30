/**
 * 中缀表达式 => 后缀表达式（逆波兰式）
 * 为确保算法的确定性 & 使先生效的运算符先出现；采用所谓 => 「运算符优先级相等则左优先的原则」
 * 
 * 输入：((5/(7-(1+1)))*3)-(2+(1+1))
 * 输出：5 7 1 1 + - / 3 * 2 1 1 + + -
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
char Pop(Stack * s) {
  if (s->top == -1) {
    return false;
  }

  char tmp = s->arr[s->top];
  // 逻辑上的出栈，实际上数据元素还残留在内存中
  s->top = s->top - 1;
  return tmp;
}

// 判栈空
bool IsEmpty(Stack s) {
  return s.top == -1;
}
/*-- 简单实现个顺序栈 --*/

/*-- Tools --*/
// 判断是否为操作数（不是运算符或界限符，则为操作数）
bool isNum(char c) {
  switch (c) {
    case '+':
    case '-':
    case '*':
    case '/':
    case '(':
    case ')':
      return false;
    default:
      return true;
  }
}

// 判断是否为运算符
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

// 判断运算符优先级高低（先算乘除后算加减）
// 若栈顶运算符优先级更低则返回 true，否则返回 false
bool isPriorityHigher(Stack s, char c) {
  char topElem = s.arr[s.top];
  if (topElem == '+' || topElem == '-') {
    if (c == '*' || c == '/') {
      return true;
    }
  }

  return false;
}
/*-- Tools --*/

void normalToReversePolishNotation(char arr[], int len) {

  // 声明并初始化一个栈，用于存放左括号和暂时还不能确定能否生效的运算符
  Stack s; InitStack(&s);

  for (int i = 0; i < len; i ++) {

    char curElem = arr[i];

    if (curElem == '(') { // 扫描到的是"("
      Push(&s, curElem);
      continue;
    }

    if (isNum(curElem)) { // 扫描到的是操作数
      printf("%c ", curElem);
      continue;
    }

    if (!isOperator(curElem)) { // 扫描到的是")"
      char res = Pop(&s);
      while (isOperator(res)) {
        printf("%c ", res);
        res = Pop(&s);
      }
      continue;
    }

    // 扫描到的是运算符

    if (IsEmpty(s)) {
      Push(&s, curElem);
      continue;
    }

    while(!IsEmpty(s)) {

      if (s.arr[s.top] == '(') {
        Push(&s, curElem);
        break;
      }

      // 栈顶运算符优先级更低
      if (isPriorityHigher(s, curElem)) {
        Push(&s, curElem);
        break;
      }

      printf("%c ", Pop(&s));

    }

  }

  while (s.top != -1) {
    printf("%c ", Pop(&s));
  }
  printf("\n");

}

int main() {

  printf("请输入一个整数，表示您希望输入一个多长的中缀表达式，按回车确认：");
  const int len;
  scanf("%d", &len);

  printf("请输入一个长度为 %d 的中缀表达式，按回车确认：", len);

  // 注意啊！这里是 len + 1，因为字符数组最后一个位置得留给'\0'
  #define size len + 1
  char NN[size];
  for (int i = 0; i < size; i ++) {
    scanf("%c", &NN[i]);
  }

  printf("您输入的中缀表达式为：\n");
  for (int i = 0; i < size; i ++) { // printf("%s\n", NN);
    printf("%c ", NN[i]);
  }
  printf("\n\n");

  printf("转化为后缀表达式如下：\n");
  normalToReversePolishNotation(NN, size);
  printf("\n");

  return 0;
}