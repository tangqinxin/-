#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<climits>
using namespace std;

int main() {
	int V, n;
	cin >> V>>n;
	int vol[31];
	for (int i = 1; i <= n; i++) {
		cin >> vol[i];
	}
	int dp[20001];
	for (int i = 0; i <=V; i++) {
		dp[i] = INT_MAX;	//dp使用恰好背包，dp[j]表示恰好花费j的空间时的最小的空间剩余量.计算的时候跳过不可能的方案(int_max)
	}
	dp[0] = V;//根据dp的定义，在一开始可以选择0种物体时，恰好花费0空间，此时空间剩余量为V；对应的，可以选择0种物体，恰好花费j空间，这是不可能的，因此假设为INT_MAX。
	for (int i = 1; i <= n; i++) {
		for (int j = V; j >= 0; j--) {
			if (j >= vol[i]&&dp[j-vol[i]]!=INT_MAX)//由于要求恰好花费j空间，因此在放入当前这个物品时，要求之前的物品占用j-vol[i]的空间，并且这个空间是有意义的，即j-vol[i]>=0
				dp[j] = min(dp[j], dp[j - vol[i]]-vol[i]);
		}
	}
	int res = INT_MAX;
	for (int i = 0; i <= V; i++) {
		res = min(res, dp[i]);
	}
	cout << res;
	return 0;
}