#include <stdio.h>

int main(void) {

  int arr[] = { 1, 2, 3 };

  for (int i = 0; i < 3; i ++) {
    for (int j = 0; j < 3; j ++) {
      for (int k = 0; k < 3; k ++) {

        if (arr[j] != arr[i] && arr[k] != arr[j] && arr[k] != arr[i]) {
          printf("%d %d %d\n", arr[i], arr[j], arr[k]);
        }

      }
    }
  }

  return 0;
}
