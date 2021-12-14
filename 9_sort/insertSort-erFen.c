
/**
 * 折半插入排序（就是使用折半查找算法，在有序子序列中查找要插入的位置）
 */

#include <stdio.h>
#define Empty -9999 // 1. 使数组下标和元素位序保持一致 2. 可被用作数据缓存空间

void _printArr(int arr[], int arrLen) {
  for (int i = 1; i < arrLen; i ++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

// 注意：本算法 arr[0] 是个空位置
void insertSort_erFen(int arr[], int arrLen) {

  if (arrLen < 3) { return; }

  for (int i = 2; i < arrLen; i ++) {

    // 摸一张牌
    arr[0] = arr[i];

    // 对有序子序列进行折半查找 ！
    int low = 1,
        high = i - 1;

    for (int mid = (low + high) / 2; low <= high; mid = (low + high) / 2) {
      // 如果想让排序算法是稳定的，那么 arr[mid] == arr[0] 时，应继续在 mid 位置的右边寻找要插入的位置
      if (arr[mid] <= arr[0]) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }

    // 当前 low 位置就是要插入的位置，先腾位置，然后插入
    for (int j = i - 1; j >= low; j--) {
      arr[j + 1] = arr[j];
    }
    arr[low] = arr[0];

  }
}

int main() {
  int arr[] = { Empty, 2, 4, 1, 6, -1, 8, 0, 2 },
      arrLen = sizeof(arr) / sizeof(int);

  insertSort_erFen(arr, arrLen);
  _printArr(arr, arrLen);
  return 0;
}
