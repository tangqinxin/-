#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
struct obj {
	int t;
	int val;
};

int main() {
	int T, M;
	cin >> T >> M;
	int dp[1005] = {0};
	obj list[105];
	for (int i = 1; i <= M; i++) {
		cin >> list[i].t >> list[i].val;
	}
	for (int i = 1; i <= M; i++) {
		for (int j = T; j >= 0; j--) {
			if(j>=list[i].t)
			dp[j] = max(dp[j], dp[j - list[i].t] + list[i].val);
		}
	}
	cout << dp[T];
	return 0;
}




/* 0-1背包未优化算法
int main() {
	int T, M;
	cin >> T >> M;
	int dp[105][1001] = {};
	obj list[105];
	for (int i = 1; i <= M; i++) {
		cin >> list[i].t >> list[i].val;
	}

	for (int i = 1; i <= M; i++) {
		for (int j = 0; j <= T; j++) {
			if (j >= list[i].t)
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - list[i].t] + list[i].val);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	cout << dp[M][T];

	return 0;
}
*/