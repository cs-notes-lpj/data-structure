/**
 * 括号匹配算法（用「顺序栈」实现）
*/

#include <stdio.h>
#define maxSize 10
typedef enum { false = 0, true } bool;

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

bool Push(SeqStack * s, int elem) {
  if ((*s).top == maxSize - 1) {
    return false;
  }

  (*s).arr[(*s).top + 1] = elem;
  (*s).top = (*s).top + 1;
  return true;
}

bool Pop(SeqStack * s, int * res) {
  if ((*s).top == -1) {
    return false;
  }

  (*res) = (*s).arr[(*s).top];
  (*s).top = (*s).top - 1;
  return true;
}

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

bool isSeqStackEmpty(SeqStack s) {
  return (s.top == -1);
}

bool matchBrackets(char arr[], int len) {

  SeqStack s; InitSeqStack(&s);

  // 开始扫描
  for (int i = 0; i < len; i ++) {
    // 如果是左括号
    if (isLeftBrackets(arr[i])) {
      Push(&s, arr[i]);
      continue;
    } else {
      // 判断栈空不空
      if (isSeqStackEmpty(s)) {
        printf("匹配失败，右括号单身\n");
        return false;
      } else {

        // 将括号进行配对
        int oldTop; Pop(&s, &oldTop);
        if (isMatch(oldTop, arr[i])) {
          continue;
        } else {
          printf("匹配失败，配对失败\n");
          return false;
        }

      }
    }
  }

  // 扫描结束，栈空吗
  if (isSeqStackEmpty(s)) {
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

  if (matchBrackets(arr3, sizeof(arr3) / sizeof(char))) {
    printf("括号匹配！");
  }

  return 0;
}
