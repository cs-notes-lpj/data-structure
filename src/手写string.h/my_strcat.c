#include <stdio.h>
#include <string.h>

/**
 * 函数原型:      char * strcat(char *restrict s1, const char *restrict s2);
 * 用途:         拷贝一份 s2 指向的字符串，将其拼接至 s1 指向的字符串的后面
 * 期望返回值:    指针 s1，故函数返回值类型为 char *
 * 注意:         restrict 关键字，用于限制 s1 和 s2 所指向的字符串不能有重叠（from C99）
 */

char * my_strcat(char *restrict destStr, const char *restrict srcStr) {

  // char * tmp = destStr;

  // while (*destStr != '\0') {
  //   destStr++;
  // }

  // while (*srcStr != '\0') {
  //   *destStr = *srcStr;
  //   destStr++;
  //   srcStr++;
  // }

  // *destStr = '\0';

  // return tmp;

  /*--代码简化--*/

  char * tmp = destStr;

  while (*destStr) {
    destStr++;
  }

  while (*srcStr) {
    *destStr++ = *srcStr++;
  }

  *destStr = '\0';

  return tmp;

}

int main(int argc, char const * argv[]) {

  char dest[50] = "This is the dest.";
  char src[] = "This is the src.";

  // printf("return=%s\n", strcat(dest, src));
  // printf("dest=%s\n", dest);
  // printf("src=%s\n", src);

  printf("return=%s\n", my_strcat(dest, src));
  printf("dest=%s\n", dest);
  printf("src=%s\n", src);

  return 0;
}
