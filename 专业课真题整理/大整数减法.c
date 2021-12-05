/*
  from《算法笔记》
  
  缘由：两个大整数做减法也可能导致超出整数的取值范围

  思路：
  
    首先比较两个数的大小，如果被减数小于减数，则交换两变量，输出负号，然后再使用 sub 函数

    sub

      从低位向高位计算，对应位相减，够减就直接减，不够减就向高位借 1 当 10

      当上下均为 0 则结束计算，注意去除高位的 0 且要保证结果至少有一位数
*/

#include <stdio.h>
#include <string.h>

typedef struct {
  int num[1000]; // 为方便数组的顺序枚举，将整数的低位存储在数组的低位
  int len;
} bigN;

void _initBigN(bigN * a, int size) {
  memset(a->num, 0, size);
  a->len = 0;
}

bigN _change(char str[]) {
  bigN res;

  res.len = strlen(str);

  for (int i = 0; i < res.len; i ++) {
    res.num[i] = str[res.len - i - 1] - '0';
  }

  return res;
}

/**
 * a < b 返回负数
 * a = b 返回 0
 * a > b 返回正数
 */
int _compare(bigN a, bigN b) {
  if (a.len != b.len) {
    return a.len - b.len;
  }

  for (int i = a.len - 1; i >= 0; i --) {
    if (a.num[i] != b.num[i]) {
      return a.num[i] - b.num[i];
    }
  }

  return 0;
}

bigN sub(bigN a, bigN b) {

  bigN res;

  for (int i = 0; i < a.len || i < b.len; i ++) {
    if (a.num[i] < b.num[i]) {
      a.num[i+1] --;
      a.num[i] += 10;
    }
    res.num[res.len ++] = a.num[i] - b.num[i];
  }

  while (res.num[res.len - 1] == 0 && res.len > 1) {
    res.len --;
  }

  return res;
}

void _print(bigN a) {
  for (int i = a.len - 1; i >= 0; i --) {
    printf("%d", a.num[i]);
  }
  printf("\n");
}

int main(void) {

  char str1[1000], str2[1000]; scanf("%999s%999s", str1, str2);

  // 初始化大整数对象，将读入的字符串存储成大整数
  bigN a; _initBigN(&a, sizeof(a.num)); a = _change(str1);
  bigN b; _initBigN(&b, sizeof(b.num)); b = _change(str2);

  if (_compare(a, b) == 0) {
    printf("0\n");
    return 0;
  }

  if (_compare(a, b) < 0) {
    bigN tmp = a;
    a = b;
    b = tmp;
    printf("-");
  }

  _print(sub(a, b));
  return 0;
}
