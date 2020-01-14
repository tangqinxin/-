#include<iostream>
#include<climits>
#include<algorithm>
#include<cstring>
using namespace std;
int mat[205][205];
int dp[205][205];
int main() {
	int m, n;
	cin >> m >> n;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> mat[i][j];
		}
	}
	//边界初始化
	for (int i = 0; i <= m + 1; i++) {
		dp[i][0] = INT_MIN;//初始化左边界
		dp[i][n + 1] = INT_MIN;//初始化右边界
	}
	for (int j = 0; j <= n+1; j++) {//初始化下边界
		dp[m + 1][j] = INT_MIN;
	}
	dp[m + 1][(n + 1) / 2] = 0;

	for (int i = m; i >= 1; i--) {
		for (int j = 1; j <= n; j++) {
			int leftdown, down, rightdown;
			//以下是对有效数字的判断，负无穷增加仍然为负无穷，没有意义
			if (dp[i + 1][j - 1] == INT_MIN) {
				leftdown = INT_MIN;
			}
			else {
				leftdown = dp[i + 1][j - 1] + mat[i][j];
			}

			if (dp[i + 1][j] == INT_MIN) {
				down = INT_MIN;
			}
			else {
				down = dp[i + 1][j] + mat[i][j];
			}

			if (dp[i + 1][j+1] == INT_MIN) {
				rightdown = INT_MIN;
			}
			else {
				rightdown = dp[i + 1][j+1] + mat[i][j];
			}

			dp[i][j] = max({ leftdown,down,rightdown });
		}
	}

	int res = INT_MIN;
	for (int j= 1; j <= n; j++) {
		res = max(res, dp[1][j]);
	}
	cout << res;
	return 0;
}