#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
int mat[55][55] = {};
int dp[55][55][55][55] = {};
int main() {
	int m, n;
	cin >> m >> n;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> mat[i][j];
		}
	}

	//for (int i = 1; i <= m; i++) {
	//	for (int j = 1; j <= n; j++) {
	//		for (int k = 1; k <= m; k++) {
	//			for (int l = j + 1; l <= n; l++) {
	//				dp[i][j][k][l] = max({ dp[i - 1][j][k - 1][l],dp[i - 1][j][k][l - 1],dp[i][j - 1][k - 1][l],dp[i][j - 1][k][l - 1] }) + mat[i][j] + mat[k][l];
	//			}
	//		}
	//	}
	//}


	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= m; k++) {
				for (int l =1; l <= n; l++) {
					if (i == k&&j == l)continue;
					else
					dp[i][j][k][l] = max({ dp[i - 1][j][k - 1][l],dp[i - 1][j][k][l - 1],dp[i][j - 1][k - 1][l],dp[i][j - 1][k][l - 1] }) + mat[i][j] + mat[k][l];
				}
			}
		}
	}
	cout << dp[m][n-1][m-1][n];
	return 0;
}