#include<iostream>
#include<vector>
using namespace std;
int maxSubArray(vector<int>& nums) {
	int n = nums.size();
	int* sum = new int[n];
	sum[0] = nums[0];
	int lastsum, max, maxmax;
	maxmax = sum[0];
	for (int j = 1; j<n; j++) {
		lastsum = 0;
		max = sum[j - 1];
		for (int i = j; i >= 0; i--) {
			lastsum += nums[i];
			max = max>lastsum ? max : lastsum;
		}
		sum[j] = max;
		maxmax = maxmax>max ? maxmax : max;
	}
	return maxmax;
}

int main() {
	vector<int> vec;
	int num;
	char ch;
	while (cin >>num) {
		vec.push_back(num);
	}
	cout << maxSubArray(vec);

	return 0;
}