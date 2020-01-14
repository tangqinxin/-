#include<iostream>
#include<cstring>
#include<climits>
#include<algorithm>
#include<cmath>
#define inf 20000
using namespace std;
int a[1005], b[1005];
int dp[1005][12001];//����dp[i][j]Ϊǰi���ƣ����²��ǡ��Ϊjʱ���������Ҫ���ƵĴ���
int N = 6000;//�����1000��ƥ�䣬ÿ��ƥ��Ĳ����Ϊ5����˲�����Ϊ+-5000
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
	}
	for (int i = 0; i < 1005; i++)
		for (int j = 0; j < 12001;j++) {
		dp[i][j] = INT_MAX-1;//��ֹ�������-1
	}
	dp[0][N] = 0;//ǡ��Ϊ[0,0]��ʱ����0
	for (int i = 1; i <= n; i++) {
		int cost = a[i] - b[i];//��i��ƥ���cost
		for (int j = -5000; j <=5000; j++) {
			if(dp[i-1][j+N-cost]<inf||dp[i-1][j+N+cost] <inf)
			dp[i][j + N] = min(dp[i - 1][j + N - cost], dp[i - 1][j + N + cost] + 1);
		}
	}

	//���ս������Ѱ��abs(j-mid)��СΪǰ���dp[i][j]����Сֵ
	int res = INT_MAX;
	int Maxdist = INT_MAX;
	for (int i = -5000; i <= 5000; i++) {
		if (dp[n][i+N] < inf) {//������һ����Чֵ
			int curdist = abs(i);
			if (Maxdist > curdist) {//������̾�ֱ���滻
				Maxdist = curdist;
				res = dp[n][i+N];
			}
			else if (Maxdist == curdist) {
				res = min(res, dp[n][i + N]);
			}
		}
	}
	cout << res;

	return 0;
}