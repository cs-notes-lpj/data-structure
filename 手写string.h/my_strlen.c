#include <stdio.h>
#include <string.h>

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
