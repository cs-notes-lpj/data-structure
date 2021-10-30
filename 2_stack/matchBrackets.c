/**
 * 括号匹配算法
*/

#include <stdio.h>
typedef enum { false = 0, true } bool;

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

bool matchBrackets(char arr[], int len) {

  // 栈用于：一边扫描，一边将左括号压入栈
  char stack[len];
  int top = -1;

  // 开始扫描
  for (int i = 0; i < len; i ++) {
    // 如果是左括号
    if (isLeftBrackets(arr[i])) {
      stack[top+1] = arr[i];
      top = top + 1;
      continue;
    } else {
      // 判断栈空不空
      if (top == -1) {
        printf("匹配失败，右括号单身\n");
        return false;
      } else {

        // 将括号进行配对
        if (isMatch(stack[top], arr[i])) {
          top = top - 1;
          continue;
        } else {
          printf("匹配失败，配对失败\n");
          return false;
        }

      }
    }
  }

  // 扫描结束，栈空吗
  if (top == -1) {
    return true;
  } else {
    printf("匹配失败，左括号单身\n");
    return false;
  }
}

int main() {

  char arr1[] = {'(', '(', '(', '(', ')', ')', ')', ')'};
  char arr2[] = {'(', '(', '(', ')', ')', '(', ')', ')'};
  char arr3[] = {'{', '(', '(', ')', ')', '[', ']', '}'};
  char arr4[] = {'{', '(', '(', ')', ']', '[', ']', '}'};     // 配对失败
  char arr5[] = {'{', '(', '(', ')', ')', '}', ']', '(', ')'};// 右括号单身
  char arr6[] = {'{', '{', '(', '(', ')', ')', '[', ']', '}'};// 左括号单身

  if (matchBrackets(arr6, sizeof(arr6) / sizeof(char))) {
    printf("括号匹配！");
  }

  return 0;
}
