/**
 * 计算两自然数的最小公倍数
 * 
 * 最小公倍 = 两数乘积 / 最大公约
 */

#include <stdio.h>

// 辅助函数：求最大公约数（穷举法）
int _GCD(int m, int n) {

  if (m == 0) { return n; }
  if (n == 0) { return m; }

  int _smaller = m < n ? m : n;

  while (m % _smaller || n % _smaller) {
    _smaller--;
  }

  return _smaller;

}

int LCM(int m, int n) {
  return (m * n / _GCD(m ,n));
}

int main() {

  printf("请给 m 赋值，按回车确认："); int m; scanf("%d", &m);
  printf("请给 n 赋值，按回车确认："); int n; scanf("%d", &n);

  printf("二者的最小公倍数为：%d\n", LCM(m, n));

  return 0;
}
