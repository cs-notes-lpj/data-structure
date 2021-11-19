/**
 * 计算两自然数的最大公约数
 * 
 * https://zhuanlan.zhihu.com/p/90131095
 * 
 */

#include <stdio.h>

/**
 * 穷举法（应付考试的最佳选择）
 * 
 * 最坏时间复杂度：执行 n 次循环体，n 为 a 和 b 中较小的数 O(n)
 * 最好时间复杂度：执行一次循环体 O(1)
 * 空间复杂度：O(1)
 */
int GCD_1(int m, int n) {

  if (m == 0) { return n; }
  if (n == 0) { return m; }

  int _smaller = m < n ? m : n;

  while (m % _smaller || n % _smaller) {
    _smaller--;
  }

  return _smaller;

}

/**
 * 辗转相除（from 欧几里得）
 * 
 * 时间复杂度：O(log(max(m, n)))
 * 
 * ------
 * 
 * 缺点：
 *    1. 大整数取模运算性能较差
 *    2. 凡涉及递归，都有 「递归工作栈溢出」 的风险
 */
int GCD_2(int m, int n) {

  int _larger = m > n ? m : n,
      _smaller = m > n ? n : m;

  if (_larger % _smaller == 0) {
    return _smaller;
  }

  return GCD_2(_larger % _smaller, _smaller);

}

/**
 * 更相减损（from《九章算术》）
 * 
 * 最坏时间复杂度：O(max(a, b)))
 * 
 * ------
 * 
 * 优点：用减法运算，而不是取模运算，避免了大整数取模性能差的问题
 * 
 * 缺点：凡涉及递归，都有 「递归工作栈溢出」 的风险，如计算 1000 和 1 的最大公约数，递归工作栈就有 1000 层
 * 
 */
int GCD_3(int m, int n) {

  int _larger = m > n ? m : n,
      _smaller = m > n ? n : m;

  if (_larger - _smaller == 0) {
    return _smaller;
  }

  return GCD_3(_larger - _smaller, _smaller);

}

int main() {

  printf("请给 m 赋值，按回车确认："); int m; scanf("%d", &m);
  printf("请给 n 赋值，按回车确认："); int n; scanf("%d", &n);

  // printf("m == %d, n == %d\n", m, n);

  printf("二者的最大公约数为：%d\n", GCD_1(m, n));
  printf("二者的最大公约数为：%d\n", GCD_2(m, n));
  printf("二者的最大公约数为：%d\n", GCD_3(m, n));

  return 0;
}