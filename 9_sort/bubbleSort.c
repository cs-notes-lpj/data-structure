/**
 * 冒泡排序（基于交换的排序）
 */

#include <stdio.h>

void _printArr(int arr[], int arrLen) {
  for (int i = 0; i < arrLen; i ++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void _swap(int * a, int * b) {;
  int tmp = *b;
  *b = *a;
  *a = tmp;
}

void bubbleSort(int arr[], int arrLen) {
  if (arrLen < 2) { return; }

  // 控制冒泡的趟数
  for (int i = 0; i < arrLen - 1; i ++) {

    int _flag = 0;

    // 一趟冒泡（会将乱序部分的最大关键字冒泡到乱序序列的最右端，排好序的部分就不用再扫描了）
    for (int j = 1; j < arrLen - i; j ++) {

      // 保障排序算法的稳定性
      if (arr[j] < arr[j - 1]) {
        _swap(&arr[j], &arr[j - 1]);

        if (_flag == 0) { _flag = 1; }
      }

    }

    if (_flag == 0) { break; }

  }
}

int main() {
  int arr[] = { 1, 2, 3, 4, 5 },
      arrlen = sizeof(arr) / sizeof(int);

  bubbleSort(arr, arrlen);
  _printArr(arr, arrlen);
  return 0;
}