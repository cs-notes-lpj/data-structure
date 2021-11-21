/*
  输入 a, b

  输出二者之间的素数

  质数（Prime number），又称素数，指在大于1的自然数中，除了1和该数自身外，无法被其他自然数整除的数（也可定义为只有1与该数本身两个正因数的数）。大于1的自然数若不是素数，则称之为合数（也称为合成数）
*/

#include <stdio.h>

int _isPrimeNum(int num) {

  if (num <= 1) { return 0; }

  int cnt = 0;

  for (int i = 1; i <= num; i ++) {
    if (num % i == 0) {
      cnt++;
    }
  }

  return cnt == 2 ? 1 : 0;

}

int main(void) {

  int a; scanf("%d", &a);
  int b; scanf("%d", &b);

  while (a <= b) {
    _isPrimeNum(a) && printf("%d ", a);
    a++;
  }

  printf("\n");
  return 0;

}
