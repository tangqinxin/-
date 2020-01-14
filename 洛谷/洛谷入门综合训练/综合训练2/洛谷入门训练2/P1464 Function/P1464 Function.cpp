#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
int dp[30][30][30];
int dfs(int a, int b, int c) {
	if (a <= 0 ||b <= 0 || c <= 0)
		return 1;
	if (a > 20 || b > 20 || c > 20) //上面这两个条件完全限制了a,b,c的范围，abc的有效范围必须是1-20;大于20的必定会回退到20
		return dfs(20, 20, 20);
	if (dp[a][b][c] != 0)
		return dp[a][b][c];//记忆化搜索，避免重复计算
	if (a < b&&b < c)
		dp[a][b][c] = dfs(a, b, c - 1) + dfs(a, b - 1, c - 1) - dfs(a, b - 1, c);
	else
		dp[a][b][c] = dfs(a - 1, b, c) + dfs(a - 1, b - 1, c) + dfs(a - 1, b, c - 1) - dfs(a - 1, b - 1, c - 1);
	return dp[a][b][c];
}

int main() {
	int num1, num2, num3;
	memset(dp, 0, sizeof(dp));
	while (cin >> num1 >> num2 >> num3) {
		if (num1 == -1 && num2 == -1 && num3 == -1)break;
		else
			printf("w(%d, %d, %d) = ", num1, num2, num3);
			cout<<dfs(num1, num2, num3)<<endl;
	}

	return 0;
}