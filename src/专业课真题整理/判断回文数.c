/**
 * 判断回文数
 * 
 * https://leetcode-cn.com/problems/palindrome-number/solution/hui-wen-shu-by-leetcode-solution/
 * 
 * ------------------------------------------
 *
 * 这些数肯定不是回文数，直接返回
 * 
 *    1. 负数
 * 
 *    2. 除数字 0 外，末尾为 0 的数
 * 
 * ------------------------------------------
 * 
 * 想法若为 「直接将整个数反转，并赋值给 _reversedNum，然后与原数字对比」
 * 
 * 由于：
 * 
 *    int 的取值范围：[ -2^31, 2^31 - 1 ]
 * 
 *    2^31 - 1 == 2147483647 <--反转--> 7463847412 > (2^31 - 1)
 * 
 * 那么：
 * 
 *    给 _reversedNum 赋值的时候就会出现 「整数溢出」 的问题
 * 
 * ------------------------------------------
 * 
 * 最终的处理方式：
 * 
 *    得到 「反转之后的 后一半」
 * 
 *    得到 「前一半」
 * 
 *    二者对比
 * 
 * ------------------------------------------
 * 
 * 空间复杂度：O(1)
 * 
 * 时间复杂度：O(lgn)
 */

#include <stdio.h>

typedef enum { false = 0, true } bool;

bool isPalindrome(int num) {

  if (num < 0 || (num != 0 && num % 10 == 0)) {
    return false;
  }

  int _pre_half = num,
      _tail_half_reversed = 0;

  while (_tail_half_reversed < _pre_half) {

    _tail_half_reversed = _tail_half_reversed * 10 + (_pre_half % 10);

    _pre_half = _pre_half / 10;

  }

  return (_pre_half == _tail_half_reversed) || (_pre_half == _tail_half_reversed / 10);

}


int main() {

  int num = 12321;

  if (isPalindrome(num)) {
    printf("「是」 回文数\n");
  } else {
    printf("「不是」 回文数\n");
  }

  return 0;
}