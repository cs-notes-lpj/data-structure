/**
 * 二路归并排序（基于归并的排序算法）
 */

#include <stdio.h>
int _tmpArrSize;

void _printArr(int arr[], int arrLen) {
  for (int i = 0; i < arrLen; i ++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

// 二路归并
void _merge(int arr[], int low, int mid, int high) {

  // 申请辅助空间
  int _tmpArr[_tmpArrSize];
  for (int i = low; i <= high; i ++) {
    _tmpArr[i] = arr[i];
  }

  // 使用二路归并，将辅助空间的数据，写回原数组
  int i = low,
      j = mid + 1,
      k = low;

  while (i <= mid && j <= high) {

    // 这里写稳定的排序算法（排序算法稳定不一定好，看实际应用场景中的需求）
    arr[k++] = _tmpArr[i] <= _tmpArr[j] ? _tmpArr[i++] : _tmpArr[j++];

  }

  while (i <= mid) { arr[k++] = _tmpArr[i++]; }
  while (j <= high) { arr[k++] = _tmpArr[j++]; }

}

// 二路归并排序
void mergeSort(int arr[], int low, int high) {

  // 参数校验
  if (low >= high) {
    return;
  }

  // 将数组一分为二
  int mid = (low + high) / 2;

  // 用归并排序算法将这两部分处理成有序的
  mergeSort(arr, low, mid);
  mergeSort(arr, mid + 1, high);

  // 对这有序的两部分用二路归并，就合成了最终的有序数组
  _merge(arr, low, mid, high);

}

int main() {

  int arr[] = { 4, -1, 7, 0, 6, 2, 8, -4, 0, 2, -1 },
      arrLen = sizeof(arr) / sizeof(int);

  _tmpArrSize = arrLen;

  mergeSort(arr, 0, arrLen - 1);

  _printArr(arr, arrLen);

  return 0;
}
