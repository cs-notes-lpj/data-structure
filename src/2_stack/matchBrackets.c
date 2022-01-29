/**
 * 括号匹配算法
 */

#include <stdio.h>
typedef enum { false = 0, true } bool;

bool isLeftBrackets(char c);
bool isMatch(char a, char b);

bool matchBrackets(char arr[], int len) {

  char stack[len];
  int top = -1;

  for (int i = 0; i < len; i ++) {

    if (isLeftBrackets(arr[i])) {
      stack[++top] = arr[i];
      continue;
    }

    // 是右括号

    if (top == -1) {
      printf("匹配失败，右括号单身...\n");
      return false;
    }

    // 栈不空

    if (isMatch(stack[top], arr[i])) {
      top = top - 1;
      continue;
    }

    // 不匹配

    printf("匹配失败...\n");
    return false;
  }

  if (top == -1) {
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
    printf("括号匹配！");
  }

  return 0;
}

/*-- Utils are under below. --*/

// 判断是否为左括号
bool isLeftBrackets(char c) {
  if (c == '(' || c == '[' || c == '{') {
    return true;
  }
  return false;
}

// 判断两个括号是否匹配成对儿
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
