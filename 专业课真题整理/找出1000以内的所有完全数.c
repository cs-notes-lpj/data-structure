/*
  如果一个数，恰好等于它的因子之和，则这个数被称为 「完全数」

  eg：
    6 的因子为 1、2、3

    6 == 1 + 2 + 3

    所以 6 是完全数

  找出 1000 以内的所有完全数，并按照以下格式输出

  6 its factors are 1 2 3
*/

#include <stdio.h>
typedef enum { false = 0, true } bool;

bool isFullNum(int num) {
  int _cnt = 0;

  for (int i = 1; i < num; i ++) {
    if (num % i == 0) {
      _cnt += i;
    }
  }

  return num == _cnt;
}

void _printFator(int num) {
  for (int i = 1; i < num; i ++) {
    if (num % i == 0) {
      printf("%d ", i);
    }
  }
  printf("\n");
}

int main(void) {

  for (int i = 1; i < 1001; i ++) {
    if (isFullNum(i)) {
      printf("%d its factors are ", i); _printFator(i);
    }
  }

  return 0;
}
