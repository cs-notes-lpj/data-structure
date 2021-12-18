/*
	一维数组的传参方式小结
*/

#include <stdio.h>

void printArr_1(int arr[], const int len);
void printArr_2(int* arr, const int len);

int main(void) {
	int arr[] = { 1, 2, 3, 4, 5, 6, 7 },
		arrLen = sizeof(arr) / sizeof(int);

	printArr_1(arr, arrLen);
	printArr_2(arr, arrLen);
	return 0;
}

/*----------------Source code for test is under below.----------------*/

void printArr_1(int arr[], const int len) {
	for (int i = 0; i < len; i ++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void printArr_2(int* arr, const int len) {
	for (int i = 0; i < len; i ++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
