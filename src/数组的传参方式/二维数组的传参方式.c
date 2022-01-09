/*
  二维数组的传参方式小结（参考了：https://blog.csdn.net/gqb_driver/article/details/8886687/）

    从计算机存储的视角对比理解 test_1 和 test_2_0：显然 test_2_0 更节省内存空间，因为它只是开辟了一个存储指针的数组

    test_2_0 和 test_2_1 本质上一样，毕竟形参 int arr[] 和形参 int* arr 就一样

    test_3 不推荐，因为写法奇葩，阅读困难
*/

#include <stdio.h>

// 必须说明第二维的长度，但若将实参和形参中的 6 统一改成 5，输出结果就会发生变化，因为 %s 打印字符串的结束标志是 \0，你得给这个看不见的 \0 留位置啊
void test_1(char arr[][6], const int len);
void test_2_0(char* arr[], const int len);
void test_2_1(char** arr, const int len);
void test_3(char (*arr)[6], const int len);

int main(void) {
  char arr_1[][6] = { "hello", "world", "good!" };
  test_1(arr_1, sizeof(arr_1) / sizeof(arr_1[0]));

  printf("-------------------------\n");

  char* arr_2[] = { "hello", "world", "good!" };
  test_2_0(arr_2, sizeof(arr_2) / sizeof(char*));
  test_2_1(arr_2, sizeof(arr_2) / sizeof(char*));

  printf("-------------------------\n");

  // char str[5] = "Hell";
  // char (*arr)[5];
  // arr = &str;
  // printf("%s\n", *arr);

  char arr_3[][6] = { "hello", "world", "good!" };
  test_3(arr_3, sizeof(arr_3) / sizeof(arr_3[0]));
}

/*----------------Source code for test is under below.----------------*/

void test_1(char arr[][6], const int len) {
  for (int i = 0; i < len; i ++) {
    printf("arr[%d] = %s\n", i, arr[i]);
  }
}

void test_2_0(char* arr[], const int len) {
  for (int i = 0; i < len; i ++) {
    printf("arr[%d] = %s\n", i, arr[i]);
  }
}

void test_2_1(char** arr, const int len) {
  for (int i = 0; i < len; i ++) {
    printf("arr[%d] = %s\n", i, arr[i]);
  }
}

void test_3(char (*arr)[6], const int len) {
  for (int i = 0; i < len; i ++) {
    printf("arr[%d] = %s\n", i, arr[i]);
  }
}
