#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int lengthOfLIS(vector<int>& nums) {
	int n = nums.size();
	vector<int> dp(n,1);//定义dp[i]为以第i个元素结尾的最长上升子序列的长度
	dp[0] = 1;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (nums[i] > nums[j])
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}
	int res = dp[0];
	for (int i = 0; i < n; i++) {
		res = max(res, dp[i]);
	}
	return res;
}

int main() {
	vector<int> vec = { 10, 9, 2, 5, 3, 7, 101, 18 };
	cout << lengthOfLIS(vec);
	return 0;
}