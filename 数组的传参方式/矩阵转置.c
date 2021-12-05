/*
  矩阵转置

  1  2  3  4        1  5  9
  5  6  7  8   ==>  2  6  10
  9  10 11 12       3  7  11
                    4  8  12

拓展：

  一行 JavaScript 代码生成转置矩阵（开辟了新的内存空间，并非原地转置）
  var arr = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12]];
  console.log(
    Array.from( { length: arr[0].length }, (_, i) => arr.map(item => item[i]) )
  );
*/

#include <stdio.h>

void _initMatrix(int row, int col, int matrix[][col]) {
  for (int i = 0; i < row; i ++) {
    for (int j = 0; j < col; j ++) {
      printf("请输入 matrix[%d][%d]：", i, j); scanf("%d", &matrix[i][j]);
    }
  }
}

void _printMatrix(int row, int col, int matrix[][col]) {
  for (int i = 0; i < row; i ++) {
    // i 定 <==> 行定，一行行输出
    for (int j = 0; j < col; j ++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

void _rPrintMatrix(int row, int col, int matrix[][col]) {
  for (int j = 0; j < col; j ++) {
    // j 定 <==> 列定，一列列输出
    for (int i = 0; i < row; i ++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

int main(void) {

  printf("请输入矩阵的行："); int row; scanf("%d", &row);
  printf("请输入矩阵的列："); int col; scanf("%d", &col);

  int matrix[row][col]; 
  _initMatrix(row, col, matrix);
  _printMatrix(row, col, matrix);

  printf("----------矩阵转置输出----------\n");
  _rPrintMatrix(row, col, matrix);
  return 0;
}
