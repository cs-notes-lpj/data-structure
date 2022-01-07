/*
  题目要求：
    1. 输入一个小于 1000 的正数， 如果不是小于 1000 的正数，则要求重新输入
    2. 求其算术平方根（非负平方根）

---
  注：
    平方根，又叫二次方根，表示为〔±√￣〕，非负平方根称为算术平方根（arithmetic square root）
    一个正数有两个实平方根，且它们互为相反数，负数没有平方根，0 的平方根是 0
---

  1. 牛顿迭代法 X_(n+1) = (X_n + a / X_n) / 2;

  2. 二分法

  Tips：很多平方根都是无理数，我们只能求得精度达标的平方根的近似值
*/

#include <stdio.h>
#include <math.h>

/** 二分法，求算术平方根的近似值
 * 
 *    eg：求 2 的算术平方根
 * 
 *    1   1.5   2  -->  1.5 * 1.5 == 2.25 > 2
 * 
 *    1   1.25   1.5  -->  1.25 * 1.25 == 1.5625 < 2
 * 
 *    1.25   1.375   1.5  -->  1.375 * 1.375 == 1.890625 < 2
 * 
 *    1.375  ...  1.5
 * 
 *    ...
 */
void printSquareRoot(double num) {
  /*
    num > 1.0 =算术平方根属于=> (1.0, num)
    num < 1.0 =算术平方根属于=> (num, 1.0)
  */

  double left = num > 1.0 ? 1.0 : num,
         right = num > 1.0 ? num : 1.0,
         center;

  while (right - left >= 1E-6) {
    center = (left + right) / 2.0;
    if (center * center > num) {
      right = center;
    } else {
      left = center;
    }
  }

  printf("%.6lf\n", left);

}

/** 牛顿迭代法，求算术平方根的近似值
 * 
 *    1. 任取 pre，进行一次迭代
 *
 *    2. 若精度不达标，则继续迭代
 * 
 *    3. 当精度达标，则输出
 */

double _fabs(double num) {
  return num < 0 ? -num : num;
}

void printSquareRoot_pro(double num) {

  double pre = num,
         this = (pre + num / pre) / 2.0;

  while (_fabs(pre - this) >= 1E-6) {
    pre = this;
    this = (pre + num / pre) / 2.0;
  }

  printf("%.6lf\n", this);

}

int main(void) {

  double num = -1;
  while (num <= 0 || num >= 1000) {
    printf("请输入一个小于 1000 的正数，按回车确认："); scanf("%lf", &num);
  }

  printSquareRoot(num);     // 二分 shit ！
  printSquareRoot_pro(num); // 牛顿 yyds ！！
  printf("%lf\n", sqrt(2)); // 即使是库函数，求出来的也是近似值 ！！！
  return 0;
}
