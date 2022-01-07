/*
  水仙花数是一个 3 位的数，即 [100, 999]

  水仙花数 == 百位的立方 + 十位的立方 + 个位的立方

  eg：153 == 1*1*1 + 5*5*5 +3*3*3

  输出所有的水仙花数
*/

#include <stdio.h>

int isShuiXianHua(int n) {

  // int ge = n % 10,
  //     shi = n / 10 % 10,
  //     bai = n / 100;
  // return n == ge*ge*ge + shi*shi*shi + bai*bai*bai;

  int cnt = 0,
      _yuShu = 0;

  // 把数分解，算立方和
  for (int _tmp = n; _tmp > 0; _tmp = _tmp / 10) {
    _yuShu = _tmp % 10;
    cnt = cnt + (_yuShu * _yuShu * _yuShu);
  }

  return n == cnt;

}

int main(void) {

  for (int i = 100; i < 1000; i ++) {
    if (isShuiXianHua(i)) {
      printf("%d 是水仙花数\n", i);
    }
  }

  return 0;
}