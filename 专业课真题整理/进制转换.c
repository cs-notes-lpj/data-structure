/*
  请你编写一程序，实现两种不同进制之间的数据转换

  输入格式：

    共 3 行，第一行是一个正整数，表示需要转换的数的进制 n（n >= 2 && n <= 16）
    第二行是一个 n 进制数，若 n > 10 则用大写字母 A～F 表示数码 10～15，且该 n 进制数对应的十进制数不超过 1000000000
    第三行也是一个正整数 m，表示转换之后的数的进制（m >= 2 && m <= 16）

  输出格式：

    一个正整数，表示转换之后的 m 进制数

  输入样例：
  
    16
    FF
    2

  输出样例

    11111111

  思路

    n 进制 ===> 十进制 ===> m 进制

    本题规定最大数为十进制的 1000000000，又因 int 的取值范围是 -2^31 ~ 2^31-1，所以 40 位的数组够用了

    Tips: 人工计算进制转换一般使用 「短除取余法」

*/

#include <stdio.h>
#include <string.h>
#include <math.h>

int n2Ten(int n, char src[]) {
  const int srcLen = strlen(src);
  int ten = 0;
  for (int i = srcLen - 1, j = 0; i >= 0; i --, j ++) {
    char tmp = src[i];
    int tmpNum;
    if (tmp >= 'A' && tmp <= 'F') {
      tmpNum = tmp - 'A' + 10;
    } else {
      tmpNum = tmp - '0';
    }

    ten += tmpNum * pow(n, j);
  }
}

int ten2M(int ten, int m, char res[]) {
  int k = 0;
  while (ten != 0) {
    int u = ten % m;
    ten /= m;

    if (u < 10) {
      res[k++] = u + '0';
    } else {
      res[k++] = u + 'A' - 10;
    }
  }
  return k;
}

void reversePrint(char res[], int k) {
  for (int t = k - 1; t >= 0; t --) {
    printf("%c", res[t]);
  }
  printf("\n");
}

int main(void) {

  int n; scanf("%d", &n);
  char src[40]; for (int i = 0; i < 40; i ++) {src[i] = 0;} scanf("%s", src);
  int m; scanf("%d", &m);

  // 首先将 n 进制的 src 转化成十进制的数
  int ten = n2Ten(n, src);

  // 然后将十进制的数转化成 m 进制
  char res[40]; for (int i = 0; i < 40; i ++) {res[i] = 0;}
  int k = ten2M(ten, m, res);

  // 最后输出
  reversePrint(res, k);
  return 0;
}
