/*
  输入正整数 n（n <= 20）打印出 n 层的杨辉三角形

  输入：4

  输出：
  1 1 1 1      1          1              1      3
  1 1 1 1  ==> 1 1    ==> 1 1     ==>   1 1     2
  1 1 1 1      1 1 1      1 2 1        1 2 1    1
  1 1 1 1      1 1 1 1    1 3 3 1     1 3 3 1   0

  空格数 + i + 1 = n ==> 空格数 = n - i - 1
*/

#include <stdio.h>

void printYangHui(int n) {

  int arr[n][n];

  for (int i = 0; i < n; i ++) {
    for (int j = 0; j < n; j ++) {
      arr[i][j] = 1;
    }
  }

  for (int i = 2; i < n; i ++) {
    for (int j = 1; j < i; j ++) {
      arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
    }
  }

  for (int i = 0; i < n; i ++) {

    for (int j = 0; j < n - i - 1; j ++) {
      printf(" ");
    }

    for (int j = 0; j <= i; j ++) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }

}

int main(void) {

  printf("请输入杨辉三角形的层数，按回车确认："); int n; scanf("%d", &n);

  printYangHui(n);

  return 0;
}
