/*
  采用递归思想，设计并实现一个函数

  其功能是：将正整数参数 n 由低位到高位倒序输出

  比如 n 为 4892，则输出 2984
*/

#include <stdio.h>

void reversePrint(int n) {

  if (n < 0) { return; }

  if (n < 10) {
    printf("%d", n);
  } else {
    printf("%d", n % 10);
    reversePrint((n - n % 10) / 10);
  }

}

int main() {

  int foo = 172030;
  reversePrint(foo);

  return 0;
}