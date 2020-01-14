#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

struct event{
	int start;
	int last;
};

int main() {
	int n, k;
	cin >> n >> k;
	event s[10005];//读取信息
	int cnt[10005];//用于记录事件的数量
	memset(cnt, 0, sizeof(cnt));
	for (int i = 1; i <= k; i++) {
		cin >> s[i].start >> s[i].last;
		cnt[s[i].start]++;
	}
	int dp[10005];//定义dp[i]为从第i时刻到n时刻的空间时间的最大值
	memset(dp, 0, sizeof(dp));
	dp[n + 1] = 0;//初始条件，没有空闲时间
	for (int i = n; i >= 1; i--) {
		if (cnt[i] == 0) {
			dp[i] = dp[i + 1] + 1;//i时刻没有要开始的任务，空间时间比i+1时刻会多1分组，多的就是第i分钟
		}
		else if (cnt[i] != 0) {//第i分钟必须有开始的任务,那就挑一个最好的来做
			for (int j = 1; j <=k; j++) {
				if (s[j].start == i) {//搜索所有k个方案中从第i分钟开始的方案
					dp[i] = max(dp[i], dp[i + s[j].last]);
				}
			}
		}
	}
	cout << dp[1];

	return 0;
}