/*
  比如：
    输入： 12345
    输出： 1 2 3 4 5
*/

#include <stdio.h>

void print(long int n) {

  if (n < 0) { return; }

  if (n < 10) { printf("%ld ", n); return; }

  long int reverseSum = 0;

  while (n) {
    reverseSum = reverseSum * 10 + n % 10;
    n /= 10;
  }

  while (reverseSum) {
    printf("%d ", reverseSum % 10);
    reverseSum /= 10;
  }

}

int main(void) {
  printf("请输入一个整数，按回车确认："); long int a; scanf("%ld", &a);
  print(a);
  return 0;
}