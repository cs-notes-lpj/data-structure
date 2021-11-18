/**
 * 汉诺塔问题
 * 
 * 参考的讲解视频已保存至阿里云盘
 */

#include <stdio.h>

void _move(char i, char j) {
  printf("%c --> %c\n", i, j);
}

// 参数含义：将 n 个盘子，从 A 借助 B 移动到 C
void hanoi(int n, char A, char B, char C) {

  if (n == 1) {
    _move(A, C);
    return;
  }

  hanoi(n-1, A, C, B);
  _move(A, C);
  hanoi(n-1, B, A, C);

}

int main() {
  hanoi(3, 'A', 'B', 'C');
  return 0;
}
