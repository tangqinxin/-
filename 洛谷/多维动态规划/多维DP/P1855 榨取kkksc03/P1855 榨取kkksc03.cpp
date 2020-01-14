#include<iostream>
#include<climits>
#include<algorithm>
#include<cstring>
using namespace std;

int dp[105][205][205];//非恰好背包
					  //定义dp[i][j][k]为，考虑前i种物品，资源1小号小于等于j，资源2消耗小于等于k时候的方案中的价值最大值
struct obj {
	int money;
	int time;
}list[105];

int main() {
	int n, M, T;
	cin >> n >> M >> T;
	for (int i = 1; i <= n; i++) {
		cin >> list[i].money >> list[i].time;
	}

	for (int i = 0; i <= n; i++) {
		dp[i][0][0] = 0;
	}

	for (int i = 1; i <= n; i++) {
		for (int m = 1; m <= M; m++) {
			for (int t = 1; t <= T; t++) {
				if (m >= list[i].money&&t >= list[i].time) {
					dp[i][m][t] = max(dp[i - 1][m][t], dp[i - 1][m - list[i].money][t - list[i].time] + 1);
				}
				else {
					dp[i][m][t] = dp[i - 1][m][t];//这里必须这么写，即使money或者time在某个维度上超过了，但仍应该继承i-1的结果，重要
				}
			}
		}
	}

	cout<<dp[n][M][T];//使用非恰好背包不需要重新搜索结果

	return 0;
}