#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

// 代码0：前面已写,在本文本中没有
// 代码1：使用恰好背包的3维解决
// 代码2：使用压缩维度的2维解决

int dp[205][205];//定义dp[j][k]为，资源1小号恰后为j，资源2消耗恰好为k时候的方案中的价值最大值
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

	memset(dp, -1, sizeof(dp));
	dp[0][0] = 0;

	for (int i = 1; i <= n; i++) {
		for (int m = M; m >= 0; m--) {
			for (int t = T; t >= 0; t--) {
				if (m >= list[i].money&&t >= list[i].time&&dp[m - list[i].money][t - list[i].time] != -1) {
					dp[m][t] = max(dp[m][t], dp[m - list[i].money][t - list[i].time] + 1);
				}
			}
		}
	}
	int res = 0;
	for (int m = 0; m <= M; m++) {//在n种中搜索结果
		for (int t = 0; t <= T; t++) {
			res = max(res, dp[m][t]);
		}
	}
	cout << res;

	return 0;
}


// 三维使用恰好背包的方法代码

//int dp[105][205][205];//定义dp[i][j][k]为，考虑前i种物品，资源1小号恰后为j，资源2消耗恰好为k时候的方案中的价值最大值
//struct obj {
//	int money;
//	int time;
//}list[105];

//int main() {
//	int n, M, T;
//	cin >> n >> M >> T;
//	for (int i = 1; i <= n; i++) {
//		cin >> list[i].money >> list[i].time;
//	}
//
//	memset(dp, -1, sizeof(dp));
//	for (int i = 0; i <= n; i++) {
//		dp[i][0][0] = 0;
//	}
//
//	for (int i = 1; i <= n; i++) {
//		for (int m = 1; m <= M; m++) {
//			for (int t = 1; t <= T; t++) {
//				if (m >= list[i].money&&t >= list[i].time&&dp[i - 1][m - list[i].money][t - list[i].time]!=-1) {//当前方案有效且不越界
//					dp[i][m][t] = max(dp[i - 1][m][t], dp[i - 1][m - list[i].money][t - list[i].time] + 1);
//				}
//				else if(dp[i - 1][m][t] != -1){//上一个方案有效，但第i种越界了,将其继承
//					dp[i][m][t] = dp[i - 1][m][t];
//				}
//			}
//		}
//	}
//	int res = 0;
//	for (int m = 0; m <= M; m++) {//在n种中搜索结果
//		for (int t = 0; t <= T; t++) {
//			res = max(res, dp[n][m][t]);
//		}
//	}
//	cout << res;
//
//	return 0;
//}