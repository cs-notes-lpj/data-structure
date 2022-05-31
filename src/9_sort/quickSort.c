/**
 * 快速排序
 * 由于只有一个辅助空间 =故=> 空间复杂度 O(1)
 */
#include <stdio.h>

void _printArr(int arr[], int arrLen) {
    for (int i = 0; i < arrLen; i ++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int _partition(int arr[], int low, int high) {
    if (low >= high) {
        return -1;
    }
    
    // 任意“提拔”一个元素成为中枢元素
    int pivot = arr[low];
    // 此时arr[low]就相当于一个空位

    while (low < high) {
        // 对中枢右侧的元素进行扫描，将遇到的第一个小于等于中枢元素的元素放到空位中（右侧只保留比中枢大的元素）
        while (low < high && arr[high] > pivot) { high--; }
        arr[low] = arr[high];
        // 此时arr[high]就相当于一个空位

        // 对中枢左侧的元素进行扫描，将遇到的第一个大于中枢元素的元素放到空位中（左侧只保留小于等于中枢的元素）
        while (low < high && arr[low] <= pivot) { low++; }
        arr[high] = arr[low];
        // 此时arr[low]就相当于一个空位
    }

    // 此时 low == high
    // 将中枢元素放入，并返回中枢元素的位置
    arr[low] = pivot;
    return low;
}

void quickSort(int arr[], int low, int high) {
    // 如果数组长度小于 2，则无需进行排序
    if (low >= high) {
        return;
    }
    
    // 如果数组长度大于 1，则将数组划分为左右子表，左子表中的元素均小于中枢，右子表中的元素均大于中枢
    // 即：[ 左子表，中枢，右子表 ]
    int pos = _partition(arr, low, high);
    if (pos < 0) {
        return;
    }

    // 最后，递归地，对左右子表采用快速排序
    // 搞定
    quickSort(arr, low, pos - 1);
    quickSort(arr, pos + 1, high);
}

int main(void) {
    int arr[] = { 3, -1, 4, 0, 6, 2, -5, 0, -1, 7, 0 },
        arrLen = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, arrLen - 1);
    _printArr(arr, arrLen);
    return 0;
}
