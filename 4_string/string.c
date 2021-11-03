/**
 * 串 & 实现重要的基本操作
 * 
 * 顺序存储 + 方案四
 * 
 * 1. 用整型变量 length 记录串长
 * 2. 废弃不用 ch[0]，让串中字符的位序和数组下标保持一致
 * 
 */

#include <stdio.h>

/*-- 定义数据结构：串 --*/
#define maxSize 255
typedef struct {
  char ch[maxSize];
  int length;
} SString;
/*-- 定义数据结构：串 --*/

/**
 * 比较串的大小
 * 注意 ch[0] 废弃不用，因此遍历从 i = 1 开始
 * - 若 S > T，则返回值 > 0
 * - 若 S = T，则返回值 = 0
 * - 若 S < T，则返回值 < 0
 */
int StrCompare(SString S, SString T) {
  // 首先比较相同长度的前缀，先出现 ASCII 码大的字符的串就大
  for (int i = 1; i <= S.length && i <= T.length; i++) {
    if (S.ch[i] != T.ch[i]) {
      return (S.ch[i] - T.ch[i]);
    }
  }

  // 前缀一模一样，要么俩串就是一样的，要么长的串更大
  return S.length - T.length;
}



int main() {
  return 0;
}