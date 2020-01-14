#include<iostream>
#include<algorithm>
using namespace std;

int v[6][6] = {
	{ 0,0,0,0,0,0 },
	{ 0,5,-1,-2,-1,-3 },
	{ 0,-1,5,-3,-2,-4 },
	{ 0,-2,-3,5,-2,-2 },
	{ 0,-1,-2,-2,5,-1 },
	{ 0,-3,-4,-2,-1,0 }
};

int main() {
	int Gen1[105];
	int Gen2[105];
	int dp[105][105] = {};
	int len1, len2;
	//读取数据进行转化
	char ch;
	cin >> len1;
	for (int i = 1; i <= len1; i++) {
		cin >> ch;
		if (ch == 'A')Gen1[i] = 1;
		if (ch == 'C')Gen1[i] = 2;
		if (ch == 'G')Gen1[i] = 3;
		if (ch == 'T')Gen1[i] = 4;
	}
	cin >> len2;
	for (int i = 1; i <= len2; i++) {
		cin >> ch;
		if (ch == 'A')Gen2[i] = 1;
		if (ch == 'C')Gen2[i] = 2;
		if (ch == 'G')Gen2[i] = 3;
		if (ch == 'T')Gen2[i] = 4;
	}
	//数据处理，计算初始值
	dp[0][0] = 0;
	for (int i = 1; i <=len1; i++) {
		dp[i][0] = dp[i - 1][0] + v[Gen1[i]][5];
	}
	for (int i = 1; i <= len2; i++) {
		dp[0][i] = dp[0][i - 1] + v[5][Gen2[i]];
	}
	//状态转移方程
	for (int i = 1; i <= len1; i++) {
		for (int j = 1; j <= len2; j++) {
			dp[i][j] = max({ dp[i - 1][j - 1] + v[Gen1[i]][Gen2[j]],dp[i - 1][j] + v[Gen1[i]][5],dp[i][j - 1] + v[5][Gen2[j]] });
		}
	}
	cout << dp[len1][len2];
	return 0;
}