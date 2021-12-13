/**
 * 数组去重（先排序）
 */

#include <stdio.h>

void _printArr(int arr[], int arrLen) {
  for (int i = 0; i < arrLen; i ++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int _partition(int arr[], int begin, int end) {
  // 选取中枢元素
  int pivot = arr[begin];

  while (begin < end) {
    // 从右边搬小的，放到左边
    while (arr[end] >= pivot && begin < end) {
      end --;
    }
    arr[begin] = arr[end];

    // 从左边搬运大的，放到右边
    while (arr[begin] < pivot && begin < end) {
      begin ++;
    }
    arr[end] = arr[begin];
  }

  // begin == end
  arr[begin] = pivot;
  return begin;
}

void _quickSort(int arr[], int begin, int end) {
  if (begin >= end) { return; }

  // 进行一次划分
  int pos = _partition(arr, begin, end);
  // 对左右两部分分别快排
  _quickSort(arr, 0, pos - 1);
  _quickSort(arr, pos + 1, end);
}

int arrFilter(int arr[], int arrLen) {
  if (arrLen < 2) {
    return arrLen;
  }

  _quickSort(arr, 0, arrLen - 1);
  // cpp -> std::sort(arr, arr + arrLen, [_compare]); <- <algorithm>

  int pos = 1;

  for (int i = 1; i < arrLen; i ++) {
    if ( arr[i] != arr[pos - 1] ) {
      arr[pos++] = arr[i];
    }
  }

  return pos;
}

int main(void) {
  
	int arr[] = { 1, 2, 1, 4, 2, 1, 4, 2, 4, 3, 5, 2, 3, 5 },
      arrLen = sizeof(arr) / sizeof(int);

  arrLen = arrFilter(arr, arrLen);
  _printArr(arr, arrLen);
  return 0;
}
