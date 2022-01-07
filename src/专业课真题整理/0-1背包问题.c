/*
  0-1 背包问题

  https://blog.csdn.net/Iseno_V/article/details/100001133/

  题目描述：

    有一个容量为 s 的背包，和 n 个物体，每个物体有两个属性（体积 v、价值 p）

    忽略物体的实际几何形状，只要背包的剩余容量 >= 物体的体积，就可以将物体装进背包里

    如何向背包装物体才能使背包中物体的总价值最大？

  Tips：

    贪心算法未必是最优解，本题用动态规划找最优解

  思考方向：

    将问题的求解划分为多个阶段，阶段之间有某种递进关系（即所谓的状态转移方程，本质就是递归的递推式）

  详细步骤：

    第一个物品能装吗？

      能装 => return max(装了第一个物品 + 剩余物品能装的最大价值，不装第一个物品 + 剩余物品能装的最大价值)

      不能装 => return 除第一个物品外其余物品能装的最大价值

  输入：
    size：8
    goods：4（{v: 2, p: 3}, {v: 3, p: 4}, {v: 4, p: 5}, {v: 5, p: 8}）
  输出：
    12（0、1、0、1）

  输入：
    size：5
    goods：4（{v: 1, p: 2}, {v: 2, p: 4}, {v: 3, p: 4}, {v: 4, p: 5}）
  输出：
    8（0、1、1、0）

  输入：
    size：40
    goods：4（{v: 15, p: 12}, {v: 10, p: 8}, {v: 12, p: 9}, {v: 8, p: 5}）
  输出：
    29（1、1、1、0）
*/

#include <stdio.h>
typedef enum { false = 0, true } bool;

typedef struct {
  int v;
  int p;
  bool choosed;
} Treasure;

void _initTreasures(Treasure treasures[], const int num) {

  printf("----正在初始化这些有价值的物体，共计 %d 个----\n", num);

  for (int i = 0; i < num; i ++) {
    treasures[i].choosed = false;
    printf("第 %d 个物体的体积为：", i + 1); scanf("%d", &treasures[i].v);
    printf("第 %d 个物体的价值为：", i + 1); scanf("%d", &treasures[i].p);
  }
}

/**
 * @param {int}         size      背包的体积
 * @param {Treasure[]}  treasures 物品
 * @param {int}         begin     数组起始下标
 * @param {int}         end       数组终止下标
 */
int cntMaxVal(int size, Treasure treasures[], int begin, int end) {

  // 背包没体积，或没有任何物品，不用处理
  if (size <= 0 || begin > end) {
    return 0;
  }

  if (treasures[begin].v > size) {
    return (
      treasures[begin].choosed = false,
      cntMaxVal(size, treasures, begin+1, end)
    );
  } else {

    int a = treasures[begin].p + cntMaxVal(size - treasures[begin].v, treasures, begin+1, end),
        b = cntMaxVal(size, treasures, begin+1, end);

    return a > b ? (
      treasures[begin].choosed = true,
      treasures[begin].p + cntMaxVal(size - treasures[begin].v, treasures, begin+1, end)
    ) : (
      treasures[begin].choosed = false,
      cntMaxVal(size, treasures, begin+1, end)
    );

  }

}

int main(void) {

  printf("请输入背包的体积："); int size; scanf("%d", &size);
  printf("请输入一共有几个物体："); int num; scanf("%d", &num); Treasure treasures[num];

  _initTreasures(treasures, num);
  printf("背包中最多能装 %d 价值的物品\n", cntMaxVal(size, treasures, 0, num - 1));

  for (int i = 0; i < num; i ++) {
    printf("体积：%d 价值：%d 是否选择：%d\n", treasures[i].v, treasures[i].p, treasures[i].choosed);
  }

  return 0;
}
