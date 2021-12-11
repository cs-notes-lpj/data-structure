/**
 * 简单选择排序
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

// [begin, end]
int _selectMin(int arr[], int begin, int end) {

  int minIdx = begin;

  for (int i = begin + 1; i <= end; i ++) {

    if (arr[i] < arr[minIdx]) {
      minIdx = i;
    }

  }

  return minIdx;

}

void simpleSelectSort(int arr[], int arrLen) {
  if (arrLen < 2) { return; }

  // 控制选择趟数
  for (int i = 0; i < arrLen - 1; i ++) {

    int minIdx = _selectMin(arr, i, arrLen - 1);

    if (i != minIdx) {
      _swap(&arr[i], &arr[minIdx]);
    }

  }
}

int main() {

  int arr[] = { -1, 9, 2, 7, -6, 0, 5 },
      arrlen = sizeof(arr) / sizeof(int);

  simpleSelectSort(arr, arrlen);
  _printArr(arr, arrlen);

  return 0;
}
