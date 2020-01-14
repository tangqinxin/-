#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int mat[105][105];
int dp[105][105];//dp[i][j]定义为以[i,j]为正方形右下角（包含[i,j]）的最大能够构成的正方形的边数
int main() {
	memset(mat, 0, sizeof(mat));
	memset(dp, 0, sizeof(dp));
	int m, n;
	cin >> m >> n;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> mat[i][j];
		}
	}
	int res = 0;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (mat[i][j] == 1) {
				dp[i][j] = min({ dp[i - 1][j],dp[i][j - 1],dp[i - 1][j - 1] }) + 1;
			}
			res = max(res, dp[i][j]);
		}
	}
	cout << res;

	return 0;
}