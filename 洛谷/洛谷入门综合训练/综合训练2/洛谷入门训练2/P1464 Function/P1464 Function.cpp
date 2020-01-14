#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
int dp[30][30][30];
int dfs(int a, int b, int c) {
	if (a <= 0 ||b <= 0 || c <= 0)
		return 1;
	if (a > 20 || b > 20 || c > 20) //����������������ȫ������a,b,c�ķ�Χ��abc����Ч��Χ������1-20;����20�ıض�����˵�20
		return dfs(20, 20, 20);
	if (dp[a][b][c] != 0)
		return dp[a][b][c];//���仯�����������ظ�����
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