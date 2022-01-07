#include <stdio.h>

int sum(int a, int b) {
  return b == 1 ? 1 : sum(a, b - 1) + b;
}

int main(void) {

  printf("%d\n", sum(1, 100));
  return 0;

}
