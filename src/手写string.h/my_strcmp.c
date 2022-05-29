#include <stdio.h>
#include <string.h>

/**
 * 函数原型: int strcmp(const char * s_1, const char * s_2);
 * 
 * 用途: 比较两个字符串
 *      s_1 == s_2 => 0
 *      s_1 > s_2  => 正
 *      s_1 < s_2  => 负
 */

int my_strcmp(const char * s_1, const char * s_2) {

  // int _idx = 0;

  // while ( 1 ) {

  //   if (s_1[_idx] != s_2[_idx]) {
  //     break;
  //   }

  //   if (s_1[_idx] == '\0') {
  //     break;
  //   }

  //   _idx++;

  // }

  // return s_1[_idx] - s_2[_idx];

  /*----代码调优----*/

  int _idx = 0;

  while ( s_1[_idx] == s_2[_idx] && s_1[_idx] != '\0' ) {

    _idx++;

  }

  return s_1[_idx] - s_2[_idx];

}

/*---另一种写法---*/
int my_strcmp_2(const char * s_1, const char * s_2) {

  while (*s_1 == *s_2 && *s_1 != '\0') {
    s_1++;
    s_2++;
  }

  return *s_1 - *s_2;

}

int main(int argc, const char * argv[]) {

  char str_1[] = "asd";
  char str_2[] = "Asd";

  printf("strcmp=%d\n", strcmp(str_1, str_2));
  printf("my_strcmp=%d\n", my_strcmp(str_1, str_2));
  printf("my_strcmp_2=%d\n", my_strcmp_2(str_1, str_2));

  return 0;
}
