#include<iostream>
#include<algorithm>
using namespace std;

short mat[2505][2505];
short horizon[2505][2505];//h[i][j]为从[i,j]开始，向左h[i][j]个单位都为0
short vertical[2505][2505];//v[i][j]为从[i,j]开始，向上v[i][j]个单位都为0
short dp1[2505][2505];//定义dp1[i][j]为：以i,j为正方形矩阵右下角,的对角线上的最大的可吃鱼数,且正方形矩阵除了对角线外不存在其他的1
short dp2[2505][2505];//定义dp1[i][j]为：以i,j为正方形矩阵左下角,的对角线上的最大的可吃鱼数,且正方形矩阵除了对角线外不存在其他的1
short h2[2505][2505];//h2[i][j]为从[i,j]开始，向右h2[i][j]个单位都为0
short v2[2505][2505];//v2[i][j]定义为从[i,j]开始，向上v2[i][j]个单位都为0，本质和vertical[2505][2505]相同


int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> mat[i][j];
		}
	}

	//计算horizon
	//初始化水平第一列都为0
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (j == 1) {
				horizon[i][j] = 0;
			}
			else if (mat[i][j-1] == 0) {
				horizon[i][j] = horizon[i][j - 1] + 1;
			}
			else if (mat[i][j - 1] != 0) {
				horizon[i][j] = 0;
			}
		}
	}

	//计算vertical
	//初始化水平第一行都为0
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i == 1) {
				vertical[i][j] = 0;
			}
			else if (mat[i-1][j] == 0) {
				vertical[i][j] = vertical[i-1][j] + 1;
			}
			else if (mat[i-1][j] != 0) {
				vertical[i][j] = 0;
			}
		}
	}

	//计算dp1[i][j]
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (mat[i][j] == 0) {
				dp1[i][j] = 0;
			}
			else if (mat[i][j] != 0) {
				dp1[i][j] = min({ dp1[i - 1][j - 1],vertical[i][j],horizon[i][j] }) + 1;
			}
		}
	}

	//计算h2[i][j]
	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= 1; j--) {
			if (j == m) {
				h2[i][j] = 0;
			}
			else if (mat[i][j + 1] == 0) {
				h2[i][j] = h2[i][j + 1] + 1;
			}
			else if (mat[i][j + 1] != 0) {
				h2[i][j] = 0;
			}
		}
	}

	//计算v2[i][j]
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i == 1) {
				v2[i][j] = 0;
			}
			else if (mat[i - 1][j] == 0) {
				v2[i][j] = v2[i - 1][j] + 1;
			}
			else if (mat[i - 1][j] != 0) {
				v2[i][j] = 0;
			}
		}
	}

	//计算dp2[i][j]
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (mat[i][j] == 0) {
				dp2[i][j] = 0;
			}
			else if (mat[i][j] != 0) {
				dp2[i][j] = min({ dp2[i - 1][j + 1],v2[i][j],h2[i][j] }) + 1;
			}
		}
	}

	short res1 = 0;
	short res2 = 0;
	short res = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			res1 = max(res1, dp1[i][j]);
			res2 = max(res2, dp2[i][j]);
			res = max(res1, res2);
		}
	}
	cout << res;

	return 0;
}