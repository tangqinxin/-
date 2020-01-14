#include<iostream>
#include<climits>
#include<algorithm>
#include<cstring>
using namespace std;

int main() {
	int n;
	int nums[105];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	int dp[105];//dp[i]的定义为：以nums[i]同学为中间，至少需要出列的人数

	//我们最终结果是求所有的dp[i]中的最小值，即出列人数的最小值
	//出列人数由左半部分和右半部分组成，左半部分是升序列，右半部分是减序列
	int left[105];
	int right[105];
	for (int i = 0; i < n; i++) {
		left[i] = 1;
		right[i] = 1;
	}
	//升序序列，以i为下标元素结尾
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (nums[i] > nums[j]) {
				left[i] = max(left[i], left[j] + 1);
			}
		}
	}
	//降序序列,以i为下标的元素为开头
	for (int i = n-1; i >= 0; i--) {
		for (int j = i; j<n; j++) {
			if (nums[i] > nums[j]) {
				right[i] = max(right[i], right[j] + 1);
			}
		}
	}
	int res = INT_MAX;
	for (int i = 0; i < n; i++) {
		dp[i] = n - (right[i] + left[i] - 1);
		res = min(res, dp[i]);
	}
	cout << res;
	return 0;
}