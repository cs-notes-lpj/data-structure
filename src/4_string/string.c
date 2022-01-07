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
typedef enum { false = 0, true } bool;

/*-- 定义数据结构：串 --*/
#define maxSize 255
typedef struct {
  char ch[maxSize];
  int length;
} SString;
/*-- 定义数据结构：串 --*/

/**
 * 比较串的大小
 * @param {SString} S 串
 * @param {SString} T 串
 * - 若 S > T，则返回值 > 0
 * - 若 S = T，则返回值 = 0
 * - 若 S < T，则返回值 < 0
 * - 注意 ch[0] 废弃不用，因此遍历从 i = 1 开始
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

/**
 * 子串拷贝
 * @param {SString *} Sub 指向串的指针
 * @param {SString} S 串
 * @param {int} pos 拷贝的起始位置
 * @param {int} len 拷贝的长度
 * - 用 Sub 返回串 S 的第 pos 个字符起长度为 len 的子串
 * - 注意 ch[0] 废弃不用
 */
bool SubString(SString * Sub, SString S, int pos, int len) {
  // 判断子串范围是否越界
  if (pos + len - 1 > S.length) {
    return false;
  }

  // 拷贝
  for (int i = pos; i < pos + len; i ++) {
    (*Sub).ch[i - pos + 1] = S.ch[i];
  }
  (*Sub).length = len; // 一定要记得写这行代码!!!

  return true;

}

/**
 * 子串定位（使用了字符串的朴素模式匹配算法的思想）
 * @param {SString} S 主串
 * @param {SString} T 测试串（模式串）
 * - 若主串 S 中存在与串 T 值相同的子串，则返回该子串第一次出现的位置，否则返回 0
 * - 注意 ch[0] 废弃不用
 */
int Index(SString S, SString T) {

  SString sub; // 用于缓存从主串 S 中截取的待比对的子串

  // 控制最多能截取比对几次
  for (int i = 1; i <= S.length - T.length + 1; i ++) {

    SubString(&sub, S, i, T.length);

    if (StrCompare(sub, T) == 0) {
      return i;
    }

  }

  // 找不到就返回
  return 0;

}

/**
 * 字符串的朴素模式匹配算法（暴力解）
 * @param {SString} S 主串
 * @param {SString} T 模式串
 * - 若主串 S 中存在与模式串 T 值相同的子串，则返回该子串第一次出现的位置，否则返回 0
 * - 注意 ch[0] 废弃不用
 */
int naivePatternMatchingAlgorithm(SString S, SString T) {

  int i = 1,
      j = 1;

  while (i <= S.length && j <= T.length) {

    if (S.ch[i] == T.ch[j]) {
      i++;
      j++;
    } else {
      i = i - j + 2;
      j = 1;
    }

  }

  return (j > T.length ? (i - T.length) : 0);

}

/**
 * 字符串的 KMP 模式匹配算法（对朴素模式匹配的优化）
 * @param {SString} S 主串
 * @param {SString} T 模式串
 * @param {int[]} next 根据模式串算出的 next 数组
 * - 若主串 S 中存在与模式串 T 值相同的子串，则返回该子串第一次出现的位置，否则返回 0（因为 ch[0] 废弃不用）
 * 
 * - 当第一个字符就发生失配时，直接对比下一个模式串（规定第 1 个字符发生失配时给 j 赋值为 0，即 next[1] 为 0，这样就能让代码的处理逻辑更统一）
 */
int Index_KMP(SString S, SString T, int next[]) {

  int i = 1,
      j = 1;

  while (i <= S.length && j <= T.length) {

    if (j == 0 || S.ch[i] == T.ch[j]) {
      i++;
      j++;
    } else {
      // 模式串右移
      j = next[j];
    }

  }

  return (j > T.length ? (i - T.length) : 0);

}

int main() {
  return 0;
}