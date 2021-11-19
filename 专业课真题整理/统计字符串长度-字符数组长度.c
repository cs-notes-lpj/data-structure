
#include <stdio.h>

int myStrLen(char * str) {

  int _len = 0;

  while ((*str) != '\0') {
    _len++;
    str++;
  }

  // if ((*str) == '\0') { printf("啊哈\n"); }

  return _len;

}

int main() {

  char str[] = "aoucnoadncoainc";

  printf("%d\n", myStrLen(str));

  return 0;
}