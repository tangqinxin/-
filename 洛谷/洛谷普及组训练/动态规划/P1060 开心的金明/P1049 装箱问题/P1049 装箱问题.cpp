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
		dp[i] = INT_MAX;	//dpʹ��ǡ�ñ�����dp[j]��ʾǡ�û���j�Ŀռ�ʱ����С�Ŀռ�ʣ����.�����ʱ�����������ܵķ���(int_max)
	}
	dp[0] = V;//����dp�Ķ��壬��һ��ʼ����ѡ��0������ʱ��ǡ�û���0�ռ䣬��ʱ�ռ�ʣ����ΪV����Ӧ�ģ�����ѡ��0�����壬ǡ�û���j�ռ䣬���ǲ����ܵģ���˼���ΪINT_MAX��
	for (int i = 1; i <= n; i++) {
		for (int j = V; j >= 0; j--) {
			if (j >= vol[i]&&dp[j-vol[i]]!=INT_MAX)//����Ҫ��ǡ�û���j�ռ䣬����ڷ��뵱ǰ�����Ʒʱ��Ҫ��֮ǰ����Ʒռ��j-vol[i]�Ŀռ䣬��������ռ���������ģ���j-vol[i]>=0
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