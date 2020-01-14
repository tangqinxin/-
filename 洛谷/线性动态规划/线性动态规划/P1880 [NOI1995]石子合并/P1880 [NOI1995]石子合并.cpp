#include<iostream> 
#include<climits>
#include<algorithm>
using namespace std;

int combine(int i, int j, int arr[]) {
	//计算合并两个部分的得分
	return arr[j] - arr[i];
}

int main() {
	int n;
	int weight[205];
	int presum[205] = {};
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> weight[i];
		weight[i + n] = weight[i];//环状数组的延长,有效的是1-2n-1的部分
	}
	for (int i = 1; i < 2 * n; i++) {
		presum[i] = presum[i - 1] + weight[i];
	}

	int maxdp[205][205] = {};//定义dp[i][j]为合并[i,j]区间能够得到的最大分数，主要是针对dp[i][i]的情况花费就是0
	int mindp[205][205] = {};
	for (int len = 2; len <= n; len++) {//枚举区间长度
		for (int l = 1; l + len - 1 < 2 * n; l++) {//l+len-1实际上就r的范围
			int r = l + len - 1;//注意，l永远不等于r
			maxdp[l][r] = INT_MIN;//分别初始化
			mindp[l][r] = INT_MAX;
			for (int k = l; k < r; k++) {//这里k<r而不是<=的原因我觉得就是因为如果k==r，k+1==r+1>r，那么dp[r+1][r]就没有意义了
				maxdp[l][r] = max(maxdp[l][r], maxdp[l][k] + maxdp[k + 1][r] + combine(l - 1, r, presum));
				mindp[l][r] = min(mindp[l][r], mindp[l][k] + mindp[k + 1][r] + combine(l - 1, r, presum));
			}
		}
	}

	int maxres, minres;
	maxres = INT_MIN;
	minres = INT_MAX;
	for (int i = 1; i <= n; i++) {
		maxres = max(maxres, maxdp[i][i + n - 1]);
		minres = min(minres, mindp[i][i + n - 1]);
	}
	cout << minres << endl;
	cout << maxres << endl;
	return 0;
}