#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * 函数原型:      char * strcpy(char *restrict dst, const char *restrict src);
 * 用途:         把 src 指向的字符串拷贝到 dst 指向的字符串（'\0' 也会被拷贝）
 * 期望返回值:    指针 dst，故函数返回值类型为 char *
 * 注意:         restrict 关键字，用于限制 src 和 dst 所指向的字符串不能有重叠（from C99）
 */

char * my_strcpy(char *restrict dst, const char *restrict src) {

  while ( 1 ) {

    *dst = *src;

    if (*dst == '\0') {
      return dst;
    } else {
      dst++;
      src++;
    }

  }

}

/*--指针版本：翁恺老师对这块讲的很棒！可以再回顾！--*/
char * my_strcpy_2(char *restrict dst, const char *restrict src) {
  // char * tmp = dst;

  // while (*src != '\0') {
  //   *dst = *src;
  //   dst++;
  //   src++;
  // }

  // *dst = '\0';

  // return tmp;

  /*-----------代码简化-----------*/
  // char * tmp = dst;

  // while (*src) {
  //   *dst++ = *src++;
  // }

  // *dst = '\0';

  // return tmp;

  /*-----------代码简化-----------*/
  char * tmp = dst;

  while ( *dst++ = *src++ ) {}

  *dst = '\0';

  return tmp;
}

int main(int argc, const char * argv[]) {

  char str[] = "asdasd";

  // char * dst = (char *)malloc(strlen(str) + 1);
  // strcpy(dst, str);
  // printf("%s##\n", dst);

  // 注意：'\0' 也得拷贝，所以得 +1
  char * dst = (char *)malloc(strlen(str) + 1);
  my_strcpy(dst, str);
  printf("%s##\n", dst);

  return 0;
}
