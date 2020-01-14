#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
struct obj {
	int v;
};

int main() {
	obj list[101];
	int N, M;//NÖÖMÔª
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> list[i].v;
	}
	vector<vector<int>> dp(N+1, vector<int>(M+1));
	dp[0][0] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			if (j >= list[i].v)
				dp[i][j] = dp[i - 1][j - list[i].v] + dp[i - 1][j];
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	cout << dp[N][M];
	return 0;
}