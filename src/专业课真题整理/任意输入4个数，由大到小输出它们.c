/*
  任意输入 4 个数，要求将这 4 数进行排序并由大到小输出
*/

#include <stdio.h>

void _swap(int * a, int * b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

int _selectMin(int arr[], int begin, int end) {

  int min = begin;

  for (int i = begin + 1; i <= end; i ++) {
    if (arr[i] < arr[min]) {
      min = i;
    }
  }

  return min;

}

void selectSort(int arr[], int arrLen) {

  if (arrLen < 2) { return; }

  for (int i = 0; i < arrLen - 1; i ++) {

    int _minIdx = _selectMin(arr, i, arrLen - 1);

    if (i != _minIdx) {
      _swap(&arr[i], &arr[_minIdx]);
    }

  }

}

int main(void) {

  // 用数组组织数据
  int arr[4],
      arrLen = sizeof(arr) / sizeof(int);

  for (int i = 0; i < arrLen; i ++) {
    scanf("%d", &arr[i]);
  }

  // 从小到大排序
  selectSort(arr, arrLen);

  // 逆序输出
  for (int i = arrLen - 1; i >= 0; i --) {
    printf("%d ", arr[i]);
  }

  printf("\n");
  return 0;
}