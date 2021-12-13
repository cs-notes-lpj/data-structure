/*
	将数组乱序

	思路：将 「交换数组中的任意两个元素」 看作一个基本操作，对数组做任意次数的基本操作
*/

#include <stdio.h>
#include <stdlib.h>
#include<time.h>

void _swap(int * a, int * b);
void _printArr(int arr[], int arrLen);

int main(void) {

	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 },
		arrLen = sizeof(arr) / sizeof(int);

	// 用当前时钟来初始化随机数种子
	srand((unsigned)time(NULL));

	// 初始化次数
	const int times = rand() % (arrLen * 5);

	for (int i = 0; i < times; i ++) {
		int idx_1 = rand() % arrLen,
			idx_2 = rand() % arrLen;

		if (idx_1 != idx_2) {
			_swap(&arr[idx_1], &arr[idx_2]);
		}
	}

	_printArr(arr, arrLen);
	return 0;
}

/*------- Source code is under below. -------*/

void _swap(int * a, int * b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void _printArr(int arr[], int arrLen) {
	for (int i = 0; i < arrLen; i ++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
