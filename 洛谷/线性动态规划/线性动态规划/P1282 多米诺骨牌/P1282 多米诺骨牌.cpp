#include<iostream>
#include<cstring>
#include<climits>
#include<algorithm>
#include<cmath>
#define inf 20000
using namespace std;
int a[1005], b[1005];
int dp[1005][12001];//定义dp[i][j]为前i对牌，上下差和恰好为j时候的最少需要翻牌的次数
int N = 6000;//最多有1000张匹配，每个匹配的差最大为5，因此差和最多为+-5000
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
	}
	for (int i = 0; i < 1005; i++)
		for (int j = 0; j < 12001;j++) {
		dp[i][j] = INT_MAX-1;//防止溢出这里-1
	}
	dp[0][N] = 0;//恰好为[0,0]的时候置0
	for (int i = 1; i <= n; i++) {
		int cost = a[i] - b[i];//第i张匹配的cost
		for (int j = -5000; j <=5000; j++) {
			if(dp[i-1][j+N-cost]<inf||dp[i-1][j+N+cost] <inf)
			dp[i][j + N] = min(dp[i - 1][j + N - cost], dp[i - 1][j + N + cost] + 1);
		}
	}

	//最终结果是搜寻以abs(j-mid)最小为前提的dp[i][j]的最小值
	int res = INT_MAX;
	int Maxdist = INT_MAX;
	for (int i = -5000; i <= 5000; i++) {
		if (dp[n][i+N] < inf) {//首先是一个有效值
			int curdist = abs(i);
			if (Maxdist > curdist) {//距离更短就直接替换
				Maxdist = curdist;
				res = dp[n][i+N];
			}
			else if (Maxdist == curdist) {
				res = min(res, dp[n][i + N]);
			}
		}
	}
	cout << res;

	return 0;
}