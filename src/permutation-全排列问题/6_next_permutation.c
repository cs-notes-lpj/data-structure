// https://leetcode-cn.com/problems/next-permutation/solution/xia-yi-ge-pai-lie-suan-fa-xiang-jie-si-lu-tui-dao-/

#include <stdio.h>

void _swap(int* a, int* b);
void _reverse(int arr[], int begin, int end);
void _printArr(int arr[], int begin, int end);
typedef enum { false = 0, true } bool;

bool count_next_permutation(int arr[], int arrLen) {
  // 寻找尽量靠右的 「较小数」
  int minIdx = -1;
  for (int i = arrLen - 1; i > 0; i --) {
    if (arr[i - 1] < arr[i]) {
      minIdx = i - 1;
      break;
    }
  }

  // 现在是最大的排列，则没有下一个排列
  if (minIdx == -1) {
    return false;
  }

  // 从右向左寻找第一个比 「较小数」 大的数
  int maxIdx = -1;
  for (int i = arrLen - 1; i > 0; i --) {
    if (arr[i] > arr[minIdx]) {
      maxIdx = i;
      break;
    }
  }

  _swap(&arr[minIdx], &arr[maxIdx]);
  _reverse(arr, minIdx + 1, arrLen - 1); // 可以证明 minIdx 后面的一定是降序，改成升序只需反序一下
  return true;
}

int main(void) {

  int arr[] = { 4, 5, 2, 6, 3, 1 },
      arrLen = sizeof(arr) / sizeof(int);

  count_next_permutation(arr, arrLen);
  _printArr(arr, 0, arrLen - 1);
  return 0;
}

/*-- Utils are under below. --*/

void _swap(int* a, int* b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void _reverse(int arr[], int begin, int end) {
  while (begin < end) {
    _swap(&arr[begin++], &arr[end--]);
  }
}

void _printArr(int arr[], int begin, int end) {
  for (int i = begin; i <= end; i ++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}
