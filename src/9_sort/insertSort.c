
/**
 * 直接插入排序（类比摸扑克牌的思想~）
 */

#include <stdio.h>

void _printArr(int arr[], int arrLen) {
  for (int i = 0; i < arrLen; i ++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void insertSort(int arr[], int arrLen) {

  // 默认第一张牌已经摸到了手里，从第二张牌开始摸
  for (int i = 1; i < arrLen; i ++) {

    int cur = arr[i], // 摸一张牌
        pos = i;      // 要插入的位置

    for (int j = i - 1; j >= 0; j --) {
      if (arr[j] > cur) {
        arr[j + 1] = arr[j];
        pos = j;
      } else {
        break;
      }
    }

    arr[pos] = cur;

  }
}

int main() {
  int arr[] = { 2, 4, 1, 6, -1, 7, 0, 2 },
      arrLen = sizeof(arr) / sizeof(int);

  insertSort(arr, arrLen);
  _printArr(arr, arrLen);
  return 0;
}
