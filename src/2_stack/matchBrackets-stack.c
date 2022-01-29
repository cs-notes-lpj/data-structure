/**
 * 括号匹配算法（用「顺序栈」实现）
*/

#include <stdio.h>
typedef enum { false = 0, true } bool;

bool isLeftBrackets(char c);
bool isMatch(char a, char b);

/*-- 顺序栈 --*/
#define maxSize 10
typedef struct {
  char arr[maxSize];
  int top;
} SeqStack;

bool InitSeqStack(SeqStack * s) {
  (*s).top = -1;

  for (int i = 0; i < maxSize; i ++) {
    (*s).arr[i] = 0;
  }
  return true;
}

bool isSeqStackEmpty(SeqStack s) {
  return (s.top == -1);
}

bool Push(SeqStack * s, char elem) {
  if ((*s).top == maxSize - 1) {
    return false;
  }

  (*s).arr[(*s).top + 1] = elem;
  (*s).top = (*s).top + 1;
  return true;
}

bool Pop(SeqStack * s, char * res) {
  if ((*s).top == -1) {
    return false;
  }

  (*res) = (*s).arr[(*s).top];
  (*s).top = (*s).top - 1;
  return true;
}
/*-- 顺序栈 --*/

bool matchBrackets(char arr[], int len) {

  SeqStack s;
  InitSeqStack(&s);

  for (int i = 0; i < len; i ++) {

    if (isLeftBrackets(arr[i])) {
      Push(&s, arr[i]);
      continue;
    }

    if (isSeqStackEmpty(s)) {
      printf("匹配失败，右括号单身...\n");
      return false;
    }

    char oldTop;
    Pop(&s, &oldTop);

    if (isMatch(oldTop, arr[i])) {
      continue;
    }

    printf("匹配失败...\n");
    return false;
  }

  if (isSeqStackEmpty(s)) {
    return true;
  }

  printf("匹配失败，左括号单身...\n");
  return false;
}

int main() {

  char arr1[] = {'(', '(', '(', '(', ')', ')', ')', ')'};
  char arr2[] = {'(', '(', '(', ')', ')', '(', ')', ')'};
  char arr3[] = {'{', '(', '(', ')', ')', '[', ']', '}'};
  char arr4[] = {'{', '(', '(', ')', ']', '[', ']', '}'};     // 匹配失败
  char arr5[] = {'{', '(', '(', ')', ')', '}', ']', '(', ')'};// 右括号单身
  char arr6[] = {'{', '{', '(', '(', ')', ')', '[', ']', '}'};// 左括号单身

  if (matchBrackets(arr6, sizeof(arr6) / sizeof(char))) {
    printf("括号匹配！\n");
  }

  return 0;
}

/*-- Utils are under below. --*/

bool isLeftBrackets(char c) {
  if (c == '(' || c == '[' || c == '{') {
    return true;
  }
  return false;
}

bool isMatch(char a, char b) {
  if (a == '(' && b == ')') {
    return true;
  }
  if (a == ')' && b == '(') {
    return true;
  }
  if (a == '[' && b == ']') {
    return true;
  }
  if (a == ']' && b == '[') {
    return true;
  }
  if (a == '{' && b == '}') {
    return true;
  }
  if (a == '}' && b == '{') {
    return true;
  }
  return false;
}
