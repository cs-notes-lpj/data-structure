/**
 * 插入排序（类比摸扑克牌的思想~）
 */
#include <stdio.h>

void _printArr(int arr[], int arrLen) {
  for (int i = 0; i < arrLen; i ++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void insertSort(int arr[], int arrLen) {

  if (arrLen < 2) { return; }

  // 将各元素插入已排好序的序列中
  for (int i = 1; i < arrLen; i ++) {

    // 摸一张牌
    int tmp = arr[i];

    // 腾位置
    int j;
    for (j = i - 1; j >= 0; j --) {

      if (tmp >= arr[j]) {
        break;
      }

      arr[j + 1] = arr[j];

    }

    // 插入
    arr[j + 1] = tmp;

  }
}

int main() {
  int arr[] = { 2, 4, 1, 6, -1, 7, 0, 2 },
      arrLen = sizeof(arr) / sizeof(int);

  insertSort(arr, arrLen);
  _printArr(arr, arrLen);

  return 0;
}
