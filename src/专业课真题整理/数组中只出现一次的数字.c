/*
  https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-ii-lcof/
  在一个数组中除一个数字只出现一次之外，其他数字都出现了三次，请找出那个只出现一次的数字
*/

int findOne(int arr[], int arrLen) {

  // The sort fn basing on quick_sort fn is picked from the cpp-library <algorithm>.
  sort(arr, arr + arrLen);

  int resIdx = 0;

  while (1) {
    if (resIdx + 2 < arrLen && arr[resIdx + 2] != arr[resIdx]) {
      return arr[resIdx];
    } else {
      resIdx += 3;
    }
  }

}
