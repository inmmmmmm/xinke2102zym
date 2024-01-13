// 用数组实现的连续邮资问题的回溯法
#include <iostream>
#include <climits>
using namespace std;

// 定义一些全局变量
const int MAXL = 1500; // 邮资上界
const int MAXINT = INT_MAX; // 大整数
int n; // 邮票的不同面值的数量
int m; // 每张信封允许贴的最多邮票数
int maxR; // 当前最优值
int x[6]; // 当前解
int y[MAXL + 1]; // 贴出各种邮资所需最少邮票数
int bestx[6]; // 当前最优解

// 定义一个函数，用回溯法求解连续邮资问题
void backtrack(int i, int r) {
    // 对于每种邮资，计算贴出它所需的最少邮票数
    for (int j = 0; j <= x[i - 2] * (m - 1); j++) {
        if (y[j] < m) {
            for (int k = 1; k <= m - y[j]; k++) {
                if (y[j] + k < y[j + x[i - 1] * k]) {
                    y[j + x[i - 1] * k] = y[j] + k;
                }
            }
        }
    }
    // 找到最大的连续邮资
    while (y[r] < MAXINT) {
        r++;
    }
    // 如果所有邮票都确定了
    if (i > n) {
        // 如果当前解优于最优解
        if (r - 1 > maxR) {
            maxR = r - 1; // 更新最优值
            for (int j = 1; j <= n; j++) {
                bestx[j] = x[j]; // 更新最优解
            }
        }
        return; // 返回上一层
    }
    // 备份y数组
    int z[MAXL + 1];
    for (int k = 1; k <= MAXL; k++) {
        z[k] = y[k];
    }
    // 枚举第i个邮票的面值
    for (int j = x[i - 1] + 1; j <= r; j++) {
        // 如果贴出r-j元邮资所需的邮票数小于m
        if (y[r - j] < m) {
            x[i] = j; // 设置第i个邮票的面值为j
            backtrack(i + 1, r + 1); // 回溯求解
            // 恢复y数组
            for (int k = 1; k <= MAXL; k++) {
                y[k] = z[k];
            }
        }
    }
}
// 定义一个函数，求解连续邮资问题的最大值
int maxStamp(int mm, int nn) {
    n = nn;
    m = mm;
    maxR = 0;
    for (int i = 1; i <= MAXL; i++) {
        y[i] = MAXINT; // 初始化为无穷大
    }
    x[1] = 1; // 第一个邮票的面值为1
    y[0] = 0; // 贴出0元邮资不需要邮票
    backtrack(2, 1); // 回溯求解
    return maxR; // 返回最大值
}



int main() {
    int m = 4; // 每张信封允许贴的最多邮票数
    int n = 5; // 邮票的不同面值的数量
    int maxR = maxStamp(m, n); // 求解连续邮资问题的最大值
    cout << "能贴出的最大邮资为：" << maxR << endl; // 输出最大值
    for (int i = 1; i <= n; i++) {
        cout << bestx[i] << " "; // 输出最优解
    }
    cout << endl;
    return 0;
}

