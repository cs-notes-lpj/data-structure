/**
 * 数组去重（保持原序）
 */

#include<stdio.h>

void _printArr(int arr[], int arrLen) {
  for (int i = 0; i < arrLen; i ++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {

  int arr[] = { 1, 2, 1, 4, 2, 1, 4, 2, 4, 3, 5, 2, 3, 5 },
      arrLen = sizeof(arr) / sizeof(int);
	
	for(int i = 0; i < arrLen; i ++) {
    
		int cur = arr[i];

		for(int j = i + 1; j < arrLen; j ++) {
			if( arr[j] == cur ) {

				for(int k = j; k < arrLen - 1; k ++) { arr[k] = arr[k + 1]; } 
				arrLen--;

				j--;

			}
		}

	}

	_printArr(arr, arrLen);
	return 0;
}
