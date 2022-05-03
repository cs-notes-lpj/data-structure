#include <cstdio>
#include <algorithm> // 为了用 sort 函数，所以改成了 .cpp

void _swap(int* a, int* b);
void _reverse(int arr[], int begin, int end);
void _printArr(int arr[], int begin, int end);
bool _count_next_permutation(int arr[], int arrLen);

void permutation(int arr[], int arrLen) {
  std::sort(arr, arr + arrLen);
  do {
    _printArr(arr, 0, arrLen - 1);
  } while (
    _count_next_permutation(arr, arrLen)
  );
}

int main(void) {

  int arr[] = { 1, 2, 3 };
  permutation(arr, 3);
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

bool _count_next_permutation(int arr[], int arrLen) {
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
