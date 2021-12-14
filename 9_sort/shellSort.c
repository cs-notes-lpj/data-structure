/*
	希尔排序

		直接插入排序在整个序列大致有序的情况下，可以获得不错的排序效率

		希尔就是看中了这一点，他希望通过合理地分组，并对各组组内使用直接插入排序，逐渐将分组缩小，以此提升排序速度

		时间复杂度可以达到 O(n^1.3) ~ O(n^2)

	思路：
		设置分组间隔（一般将分组间隔设置为数组元素个数的一半）

		while (分组间隔 >= 1) {
			分组
			对每个分组组内使用直接插入排序
			将分组间隔减半
		}
*/

#include <stdio.h>

void _printArr(int arr[], int arrLen) {
	for (int i = 0; i < arrLen; i ++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void _insertSort(int arr[], int arrLen, int gap) {

	// 默认第一张牌已经摸到了手里，从第二张牌开始摸
	for (int i = gap; i < arrLen; i += gap) {

		int cur = arr[i], // 摸一张牌
			pos = i;	  // 要插入的位置

		for (int j = i - gap; j >= 0; j -= gap) {
			if (arr[j] > cur) {
				arr[j + gap] = arr[j];
				pos = j;
			} else {
				break;
			}
		}

		arr[pos] = cur;

	}
}

void shellSort(int arr[], int arrLen) {
	int gap = arrLen / 2;

	while (gap) {
		for (int i = 0; i < gap; i ++) {
			_insertSort(arr, arrLen, gap);
		}
		gap /= 2;
	}
}

int main(void) {

	int arr[] = { 2, 4, 1, 6, -1, 8, 0, 2, 5 },
		arrLen = sizeof(arr) / sizeof(int);

		// { -1, 4, 0, 2, 2, 8, 1, 6, 5 }

	shellSort(arr, arrLen);
	_printArr(arr, arrLen);
	return 0;
}
