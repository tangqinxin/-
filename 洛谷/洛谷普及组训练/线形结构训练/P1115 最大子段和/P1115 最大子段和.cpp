#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int dp[200005];
	int N,num;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		if (i == 0) {
			dp[0] = num;
		}
		else {
			dp[i] = max(dp[i - 1] + num, num);
		}
	}
	int res = dp[0];
	for (int i = 0; i < N; i++) {
		res = max(res, dp[i]);
	}
	cout << res;
	return 0;
}