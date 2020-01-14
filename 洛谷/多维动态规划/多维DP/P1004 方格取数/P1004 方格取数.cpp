#include<iostream>
#include<algorithm>
using namespace std;

int mat[15][15] = {};
int dp[15][15][15][15] = {};

int main() {
	int n;
	cin >> n;
	while (1) {
		int i, j, val;
		cin >> i >> j >> val;
		if (i == 0 && j == 0 && val == 0)break;
		mat[i][j] = val;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				for (int l = 1; l <= n; l++) {
					if (i == k&&j == l) {
						dp[i][j][k][l] = max({ dp[i - 1][j][k - 1][l],dp[i - 1][j][k][l - 1],dp[i][j - 1][k][l - 1],dp[i][j - 1][k - 1][l] }) + mat[i][j];
					}
					else {
						dp[i][j][k][l] = max({ dp[i - 1][j][k - 1][l],dp[i - 1][j][k][l - 1],dp[i][j - 1][k][l - 1],dp[i][j - 1][k - 1][l] }) + mat[i][j] + mat[k][l];
					}
				}
			}
		}
	}

	cout << dp[n][n][n][n];
	return 0;
}