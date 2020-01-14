#include<iostream>
#include<algorithm>
#include<cstring>
#include<set>
#include<string>
#include<vector>
using namespace std;

struct obj {
	int v;
	int p;
	int q;
};

int main() {
	obj list[61];
	int N, m;
	cin >> N >> m;
	int cnt[61] = {};//统计每一组的件的数量
	int groups = 0;//统计有多少组
	obj GroupDivision[61][61];//建立一个分组的数组
	
	for (int i = 1; i <= m; i++) {
		cin >> list[i].v >> list[i].p >> list[i].q;
		groups = max(groups, list[i].q);
		if (list[i].q) {//如果是附件
			cnt[list[i].q]++;//对应的组的附件计数增加
			GroupDivision[list[i].q][cnt[list[i].q]].v = list[i].v;//填充信息
			GroupDivision[list[i].q][cnt[list[i].q]].p = list[i].p;
			GroupDivision[list[i].q][cnt[list[i].q]].q = list[i].q;
		}
	}

	/*思路：每一组内，所有的选择方案是互斥的，每一种方案可以看成是分组背包内的一个物品。
	假设该组内部有n1个物品，那么对于每个物品可以选可以不选，共有2^n1种方案，加上主件选不选共有2^n1+1种方案*/
	//对每一个组内的背包做一次01规划
	//int dp[32001];
	int dp[201];
	int cnt2[61] = {};
	int V[61][11] = {};
	int P[61][11] = {};
	for (int i = 1; i <= m; i++) {
		if (!list[i].q) {//如果是主件
			memset(dp, -1, sizeof(dp));
			dp[0] = 0;
			for (int k = 1; k <= cnt[i]; k++) {
				for (int j = N - list[i].v; j >= 0; j--) {
					if (j >= GroupDivision[i][k].v&&dp[j - GroupDivision[i][k].v] != -1)
						dp[j] = max(dp[j], dp[j - GroupDivision[i][k].v] + GroupDivision[i][k].v*GroupDivision[i][k].p);
				}
			}
			//01背包处理完之后，得到的dp[j]的含义是：对于第i组的物品，恰好花费j元的附件的钱，能够得到的最大的利益；每一个j对应一个方案，互相排斥
			//遍历完该主件的组之后，还需要对这个组内有效的方案进行记录，这个记录应该在主件内部才进行记录
			for (int j = 0; j <= N - list[i].v; j++) {
				if (dp[j] != -1) {
					cnt2[i]++;
					V[i][cnt2[i]] = j + list[i].v;
					P[i][cnt2[i]] = dp[j] + list[i].v*list[i].p;
				}
			}
		}
		//下面这个判断我觉得和j==0的判断是重复了，其实可以不写
		if (!list[i].q) {
			cnt2[i]++;
			V[i][cnt2[i]] = list[i].v;
			P[i][cnt2[i]] = list[i].v*list[i].p;
		}
	}
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= m; i++) {
		for (int j = N; j >= 0; j--) {
			for (int k = 1; k <= cnt2[i]; k++) {
				if (j >= V[i][k])
					dp[j] = max(dp[j], dp[j - V[i][k]] + P[i][k]);
			}
		}
	}
	int res = 0;
	for (int j = 0; j <= N; j++) {
		res = max(res, dp[j]);
	}
	cout << res;

	return 0;
}