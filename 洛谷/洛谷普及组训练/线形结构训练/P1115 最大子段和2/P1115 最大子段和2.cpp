#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

void SumBack(int a[], int n,int pos) {
	for (int i = pos; i >= 0; i--) {
		a[i] += n;
	}
}

int main() {
	int dp[20005];
	int backsum[20005] = {};
	int n;
	cin >> n;
	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (i == 0) {
			dp[0] = num;
			backsum[0] = num;
		}
		else {
			int temp = INT_MIN;
			for (int j = i; j >= 0; j--) {
				backsum[j] += num;
				temp = max(temp, backsum[j]);
			}
			dp[i] = max(dp[i - 1], temp);
		}
	}
	cout << dp[n-1];

	return 0;
}