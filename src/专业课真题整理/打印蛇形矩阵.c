/*
  输入 n（< 30）打印蛇形矩阵

  1 2 ==> n = 2 ==> 3（2n - 1）
  3 4

  1 2 6
  3 5 7 ==> n = 3 ==> 5（2n - 1）
  4 8 9

  1  2  6  7  15
  3  5  8  14 16
  4  9  13 17 22 ==> n = 5 ==> 7（2n - 1）
  10 12 18 21 23
  11 19 20 24 25

  [0][0]  0

  [0][1]  1
  [1][0]

  [2][0]  2
  [1][1]
  [0][2]

  [0][3]  3
  [1][2]
  [2][1]
  [3][0]

  [4][0]  4
  [3][1]
  [2][2]
  [1][3]
  [0][4]

  [1][4]  5
  [2][3]
  [3][2]
  [4][1]

  [4][2]  6
  [3][3]
  [2][4]

  [3][4]  7
  [4][3]

  [4][4]  8
*/

#include <stdio.h>

int main(void) {

  printf("请输入蛇形矩阵的阶数："); int n; scanf("%d", &n);

  int matrix[n][n];
  int begin = 1;

  for (int i = 0; i < 2 * n - 1; i ++) {

    if (i < n) {

      if (i % 2 == 1) {
        for (int j = 0; j <= i; j ++) {
          matrix[j][i - j] = begin++;
        }
      } else {
        for (int j = i; j >= 0; j --) {
          matrix[j][i - j] = begin++;
        }
      }

    } else {

      if (i % 2 == 1) {
        for (int j = 0, colBegin = n - 1; j < 2 * n - 1 - i; j ++, colBegin --) {
          matrix[i - colBegin][colBegin] = begin++;
        }
      } else {
        for (int j = 0, rowBegin = n - 1; j < 2 * n - 1 - i; j ++, rowBegin --) {
          matrix[rowBegin][i - rowBegin] = begin++;
        }
      }
      
    }

  }

  for (int i = 0; i < n; i ++) {
    for (int j = 0; j < n; j ++) {
      printf("%d\t", matrix[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  return 0;
}
