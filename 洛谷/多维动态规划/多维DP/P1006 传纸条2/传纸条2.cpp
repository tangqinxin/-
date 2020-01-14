#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
int mat[55][55] = {};
int dp[110][55][55] = {};//dp[len][i][k];
int main() {
	int m, n;
	cin >> m >> n;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> mat[i][j];
		}
	}

	for (int len = 1; len <= m + n - 1; len++) {
		for (int i = 1; i <= m; i++) {
			for (int k = 1; k <= m; k++) {
				if (i == k)continue;
				if (len - i< 1 || len - k < 1)continue;
				dp[len][i][k] = max({ dp[len - 1][i][k],dp[len - 1][i - 1][k],dp[len - 1][i][k - 1],dp[len - 1][i - 1][k-1] }) + mat[i][len - i] + mat[k][len - k];
			}
		}
	}

	cout << dp[m + n - 1][m][m-1];
	return 0;
}