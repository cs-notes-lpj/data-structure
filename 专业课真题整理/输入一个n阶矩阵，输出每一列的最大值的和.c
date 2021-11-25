/*
  输入一个 N 阶矩阵

  输出每一列的最大值的和
*/

#include <stdio.h>

int main(void) {

  printf("请输入一个正整数，表示你想输入一个几阶的矩阵，按回车确认："); int N; scanf("%d", &N);

  int arr[N][N]; printf("正在创建 %d 阶矩阵...\n", N);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j ++) {
      printf("请输入第 %d 行，第 %d 列的元素，按回车确认：", i, j); scanf("%d", &arr[i][j]);
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j ++) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }

// -------------------------------

  int sum = 0;

  // 按列数循环
  for (int i = 0; i < N; i ++) {
    // 输出当前列的最大值
    int curColMax = 0;
    for (int j = 0; j < N; j ++) {
      if (arr[j][i] > curColMax) { curColMax = arr[j][i]; }
    }
    sum += curColMax;
  }

  printf("%d\n", sum);

// -------------------------------

  return 0;
}