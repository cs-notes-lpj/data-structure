/*
  e 约等于 1 + 1 / 1！+ 1 / 2！+ 1 / 3！+ 1 / 4！+ ...
*/

#include <stdio.h>

int main(void) {

  int n; scanf("%d", &n);

  double e = 1.0, fenMu = 1.0;

  for (int i = 1; i <= n; i ++) {

    fenMu = fenMu * i;

    e = e + 1 / fenMu;

  }

  printf("%.8f\n", e);

  return 0;

}
