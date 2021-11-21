#include <stdio.h>
#include <string.h>

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