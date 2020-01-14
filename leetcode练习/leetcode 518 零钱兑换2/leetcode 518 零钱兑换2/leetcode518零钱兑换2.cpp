#include<iostream>
#include<vector>
using namespace std;
int change(int amount, vector<int>& coins) {
	int n = coins.size();
	int** dp = new int*[coins.size() + 1];
	for (int i = 0; i<=coins.size(); i++) {
		dp[i] = new int[amount + 1];
	}
	dp[0][0] = 1;
	for (int i = 1; i <= amount; i++) {
		dp[0][i] = 0;//³õÊ¼»¯
	}
	int temp;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= amount; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j - coins[i - 1] >= 0)
				dp[i][j] += dp[i][j - coins[i - 1]];
		}
	}

	return dp[n][amount];
}

int main() {
	int amount = 5;
	vector<int> vec = { 1,2,5 };
	cout<<change(amount, vec);

	return 0;
}