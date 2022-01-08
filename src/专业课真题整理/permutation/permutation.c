// 暴力解

#include <stdio.h>

int main(void) {

  int n = 3;

  for (int i = 1; i <= n; i ++) {
    for (int j = 1; j <= n; j ++) {
      for (int k = 1; k <= n; k ++) {
        if (j != i && k != i && k != j) {
          printf("%d %d %d\n", i, j, k);
        }
      }
    }
  }

  return 0;
}
