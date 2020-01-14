#include<iostream>
#include<vector>
using namespace std;

int f(vector<int>& vec) {
	int n = vec.size();
	int* dp = new int[n];
	for (int i = 0; i < n; i++) {
		dp[i] = 0;
	}
	dp[0] = 1;
	int prev,sum;
	for (int j = 1; j < n; j++) {
		prev = dp[j - 1];
		sum = 0;
		for (int i = j; i > 0; i--) {
			sum++;
			if (vec[i] < vec[i - 1]) {
				break;
			}
		}
		dp[j] = prev > sum ? prev : sum;
	}
	return dp[n-1];
}

int f2(vector<int>& vec) {
	int n = vec.size();
	int* dp = new int[n];
	int k = 1;
	dp[0] = 1;
	for (int i = 1; i < n; i++) {
		if (vec[i] > vec[i - 1]) {
			k++;
			dp[i] = k;
		}
		else {
			k = 1;
			dp[i] = k;
		}
	}
	int max = 1;
	for (int i = 0; i < n; i++) {
		max = max > dp[i] ? max : dp[i];
	}
	return max;
}

int f3(int a[],int N) {
	int n = N;
	int* dp = new int[n];
	int k = 1;
	dp[0] = 1;
	for (int i = 1; i < n; i++) {
		if (a[i] > a[i - 1]) {
			k++;
			dp[i] = k;
		}
		else {
			k = 1;
			dp[i] = k;
		}
	}
	int max = 1;
	for (int i = 0; i < n; i++) {
		max = max > dp[i] ? max : dp[i];
	}
	return max;
}

int f4(int a[], int N) {
	int n = N;
	int* dp = new int[n];
	for (int i = 0; i < n; i++) {
		dp[i] = 0;
	}
	dp[0] = 1;
	int prev, sum;
	for (int j = 1; j < n; j++) {
		prev = dp[j - 1];
		sum = 0;
		for (int i = j; i > 0; i--) {
			sum++;
			if (a[i] < a[i - 1]) {
				break;
			}
		}
		dp[j] = prev > sum ? prev : sum;
	}
	return dp[n - 1];
}

int main() {
	int N;
	int num;
	cin >> N;
	/*
	vector<int> vec;
	for (int i = 0; i < N; i++) {
		cin >> num;
		vec.push_back(num);
	}
	*/
	int* arr = new int[N];
	for (int i = 0; i < N; i++) { cin >> arr[i]; }
	int count = f3(arr,N);
	cout << count;
	return 0;
}