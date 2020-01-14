#include<iostream> 
#include<climits>
#include<algorithm>
using namespace std;

int combine(int i, int j, int arr[]) {
	//����ϲ��������ֵĵ÷�
	return arr[j] - arr[i];
}

int main() {
	int n;
	int weight[205];
	int presum[205] = {};
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> weight[i];
		weight[i + n] = weight[i];//��״������ӳ�,��Ч����1-2n-1�Ĳ���
	}
	for (int i = 1; i < 2 * n; i++) {
		presum[i] = presum[i - 1] + weight[i];
	}

	int maxdp[205][205] = {};//����dp[i][j]Ϊ�ϲ�[i,j]�����ܹ��õ�������������Ҫ�����dp[i][i]��������Ѿ���0
	int mindp[205][205] = {};
	for (int len = 2; len <= n; len++) {//ö�����䳤��
		for (int l = 1; l + len - 1 < 2 * n; l++) {//l+len-1ʵ���Ͼ�r�ķ�Χ
			int r = l + len - 1;//ע�⣬l��Զ������r
			maxdp[l][r] = INT_MIN;//�ֱ��ʼ��
			mindp[l][r] = INT_MAX;
			for (int k = l; k < r; k++) {//����k<r������<=��ԭ���Ҿ��þ�����Ϊ���k==r��k+1==r+1>r����ôdp[r+1][r]��û��������
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