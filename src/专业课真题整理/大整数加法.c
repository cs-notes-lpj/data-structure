/*
  from《算法笔记》
  
  缘由：两个大整数直接相加会导致超出整数的取值范围
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
 * 刚开始进位为 0，从低位向高位计算
 * 
 * 对应位相加，再加上进位，结果的个位成为当前位的结果，结果的十位进位
 */
bigN add(bigN a, bigN b) {

  bigN res;

  // 进位
  int carry = 0;

  // 以较长的为界限
  for (int i = 0; i < a.len || i < b.len; i ++) {
    int tmp = a.num[i] + b.num[i] + carry;
    res.num[res.len++] = tmp % 10;
    carry = tmp / 10;
  }

  // 若最后进位不为 0 则直接赋给结果的最高位
  if (carry) {
    res.num[res.len++] = carry;
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

  _print(add(a, b));
  return 0;
}
