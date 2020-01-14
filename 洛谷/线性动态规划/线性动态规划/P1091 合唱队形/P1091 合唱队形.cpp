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
	int dp[105];//dp[i]�Ķ���Ϊ����nums[i]ͬѧΪ�м䣬������Ҫ���е�����

	//�������ս���������е�dp[i]�е���Сֵ����������������Сֵ
	//������������벿�ֺ��Ұ벿����ɣ���벿���������У��Ұ벿���Ǽ�����
	int left[105];
	int right[105];
	for (int i = 0; i < n; i++) {
		left[i] = 1;
		right[i] = 1;
	}
	//�������У���iΪ�±�Ԫ�ؽ�β
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (nums[i] > nums[j]) {
				left[i] = max(left[i], left[j] + 1);
			}
		}
	}
	//��������,��iΪ�±��Ԫ��Ϊ��ͷ
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