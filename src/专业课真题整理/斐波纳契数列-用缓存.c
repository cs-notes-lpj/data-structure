/**
 * 打印斐波那契数列
 * 
 * 解释：输入一个正整数 n，打印前 n 项的斐波那契数列
 * 
 * 样例：
 *    输入：5
 *    输出：1 1 2 3 5
 */

#include <stdio.h>
#include <string.h>

// 用于缓存斐波那切数列，避免重复计算
int _cache[100];

// 辅助性工具函数，打印斐波纳契数列
void _printFib(int num);

int Fibonacci(int Idx) {
  if (Idx == 0 || Idx == 1) {
    return 1;
  }

  int before_one_Idx = Idx - 1,
      before_two_Idx = Idx - 2;

  // 实现缓存
  if (_cache[before_one_Idx] == 0) {
    _cache[before_one_Idx] = Fibonacci(before_one_Idx);
  }
  if (_cache[before_two_Idx] == 0) {
    _cache[before_two_Idx] = Fibonacci(before_two_Idx);
  }

  // 读取缓存
  return _cache[before_one_Idx] + _cache[before_two_Idx];
}

int main(void) {

  int num; scanf("%d", &num);

  // 初始化缓存（擦洗内存脏数据）
  memset(_cache, 0, 100);

  _printFib(num);

  return 0;
}

/*-- Utils are under below. --*/

void _printFib(int num) {
  for (int i = 0; i < num; i ++) {
    printf("%d ", Fibonacci(i));
  }
  printf("\n");
}
