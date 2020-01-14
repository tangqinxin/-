#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
int kConcatenationMaxSum(vector<int>& arr, int k) {
	if (arr.size() == 0)return 0;
	int N = k*arr.size() - 1;
	int sum = 0;
	int index=0;
	int max = 0;
	for (int i = 0; i <= N; i++,index++) {
		if (index > arr.size() - 1) {
			index = 0;
		}
		sum += arr[index];
		if (sum < 0) {
			sum = 0;
		}
		max = max > sum ? max : sum;
	}
	return max;
}

int kConcatenationMaxSum2(vector<int>& arr, int k) {
	int n = arr.size();
	int* ForwardSum = new int[n];
	int* BackwardSum = new int[n];
	memset(ForwardSum, 0, sizeof(ForwardSum));
	memset(BackwardSum, 0, sizeof(BackwardSum));
	int Maxf, Maxb;
	Maxf = Maxb = 0;

	int Arrsum = arr[0];//序列全部和
	ForwardSum[0] = arr[0];
	Maxf = Maxf > ForwardSum[0] ? Maxf : ForwardSum[0];
	for (int i = 1; i < arr.size(); i++) {
		Arrsum += arr[i];
		ForwardSum[i] = ForwardSum[i - 1] + arr[i];
		Maxf = Maxf > ForwardSum[i] ? Maxf : ForwardSum[i];
	}

	BackwardSum[n - 1] = arr[n - 1];
	Maxb = Maxb > BackwardSum[n-1] ? Maxb : BackwardSum[n-1];
	for (int i = n-2; i >=0; i--) {
		BackwardSum[i] = BackwardSum[i + 1] + arr[i];
		Maxb = Maxb > BackwardSum[i] ? Maxb : BackwardSum[i];
	}

	int sum = 0;//临时存放
	int maxsum = 0;//最大子列和
	for (int i = 0; i < n; i++) {
		if (sum + arr[i] > 0) {
			sum += arr[i];
		}
		else {
			sum = 0;
		}
		maxsum = maxsum > sum ? maxsum : sum;
	}

	int TwoPart;
	TwoPart = Maxf > Maxb ? Maxf : Maxb;
	TwoPart = TwoPart > (Maxf + Maxb) ? TwoPart : (Maxf + Maxb);

	int maxval=maxsum > TwoPart ? maxsum : TwoPart;

	if (k == 1)return maxsum;
	if (k == 2) {
		return maxval;
	}
	else if (Arrsum < 0) {
		return maxval;
	}
	else {
		int result;
		result = (k - 2)*Arrsum + TwoPart;
		return result;
	}
}



int main() {
	vector<int> vec = { 1,2 };
	cout<<kConcatenationMaxSum2(vec, 3);

	return 0;
}