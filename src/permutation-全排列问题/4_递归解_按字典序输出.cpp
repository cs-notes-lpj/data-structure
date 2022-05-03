#include <cstdio>
#include <algorithm> // 为了用 sort 函数，所以改成了 .cpp

void _printArr(int arr[], int begin, int end);
void _swap(int arr[], int a, int b);

void permutation(int arr[], int begin, int end) {
  if (begin > end) { return; }
  if (begin == end) { _printArr(arr, 0, end); return; }

  for(int i = begin; i < end + 1; i ++) {
    _swap(arr, i, begin);

    // 让 arr[begin + 1, end] 按照升序排列
    int _bakArr[end + 1];
    for (int j = begin + 1; j <= end; j ++) { _bakArr[j] = arr[j]; }
    std::sort(arr + begin + 1, arr + end + 1);

    permutation(arr, begin + 1, end);

    // 把 arr[begin + 1, end] 恢复到排序之前的样子
    for (int j = begin + 1; j <= end; j ++) { arr[j] = _bakArr[j]; }

    _swap(arr, i, begin);
  }
}

int main(void) {
  int arr[] = { 1, 2, 3, 4 },
      arrLen = sizeof(arr) / sizeof(int);

  permutation(arr, 0, arrLen - 1);
  return 0;
}

/*-- Utils are under below. --*/

void _printArr(int arr[], int begin, int end) {
  for (int i = begin; i <= end; i ++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void _swap(int arr[], int a, int b) {
  int tmp = arr[a];
  arr[a] = arr[b];
  arr[b] = tmp;
}
