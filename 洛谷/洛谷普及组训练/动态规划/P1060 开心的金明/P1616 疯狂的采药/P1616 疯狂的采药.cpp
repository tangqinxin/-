#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int main() {
	int T, M;
	cin >> T >> M;
	int cost[10005];
	int val[10005];
	int dp[100005];
	for (int i = 1; i <= M; i++) {
		cin >> cost[i] >> val[i];
	}
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= M; i++) {
		for (int j =cost[i]; j <= T; j++) {
				dp[j] = max(dp[j], dp[j - cost[i]] + val[i]);
		}
	}
	cout << dp[T];//其实这里应该遍历一次才是正解
	return 0;
}