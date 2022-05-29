#include <stdio.h>
#include <string.h>

/**
 * 函数原型: size_t strlen(const char * s);
 * 用途:    计算 s 指向的字符串的长度「不包括结尾的 '\0'，故比使用 sizeof 计算少 1」！
 */

size_t my_strlen(const char * s) {

  // int _cnt = 0,
  //     _idx = 0;

  // while (s[_idx] != '\0') {
  //   _cnt++;
  //   _idx++;
  // }

  // return _cnt;

  /*----代码调优----*/

  int _idx = 0;

  while (s[_idx] != '\0') {
    _idx++;
  }

  return _idx;
}

int main(int argc, const char * argv[]) {

  char str[] = " as  dasd";
  printf("strlen=%lu\n", strlen(str));
  printf("my_strlen=%lu\n", my_strlen(str));

  return 0;
}
