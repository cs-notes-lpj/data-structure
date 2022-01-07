/*
概述：
  输出空心正方形
问题：
  输入：
    在一行中给出正方形边长 N 和组成正方形边的某种字符 C，间隔一个空格
  输出：
    由给定字符 C 画出的正方形，但是注意到行间距比列间距大，为了让结果看上去更像正方形，输出的行数实际上是列数的 50%（四舍五入取整）
样例：
  输入样例：10 a
  输出样例：
    aaaaaaaaaa       aaaaaaaaaa
    aaaaaaaaaa       a        a
    aaaaaaaaaa  ==>  a        a
    aaaaaaaaaa       a        a
    aaaaaaaaaa       aaaaaaaaaa
*/

#include <stdio.h>

/**
 * @param {int}   N  正方形边长
 * @param {char}  C  某种字符
 */
void printSquare(int N, char C) {

  for (int i = 0; i < N; i ++) { printf("%c", C); }
  printf("\n");

  for (int i = 0; i < N / 2 - 2; i ++) {
    for (int j = 0; j < N; j ++) {
      if (j == 0 || j == N - 1) {
        printf("%c", C);
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }

  for (int i = 0; i < N; i ++) { printf("%c", C); }
  printf("\n");

}

int main(void) {

  int N; char C; scanf("%d %c", &N, &C);

  N = N / 2.0 + 0.5; // 四舍五入

  printSquare(N, C);

  return 0;
}
