#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
struct obj {
	int weight;
	int val;
	int num;
	obj(int a, int b, int c) :weight(a), val(b), num(c) {}
	obj():weight(0),val(0),num(0){}
};
int main() {
	int m, n, cn;
	cin >> m >> n;//weight,num of items
	int a, b, c;
	vector<vector<obj>> list(101,vector<obj>(1));
	int groups = 0;
	int numofparts[1001];
	for (int i = 1; i <= n; i++) {
		cin >> a >> b >> c;
		groups = max(c, groups);
		list[c].push_back(obj(a, b, c));
	}

	int dp[1001];
	memset(dp, 0, sizeof(dp));
	for (int k = 1; k <= groups; k++) {
		for (int j = m; j >= 0;j--) {
			for (int i = 1; i <= list[k].size() - 1; i++) {
				if (j >= list[k][i].val)
					dp[j] = max(dp[j], dp[j - list[k][i].weight] + list[k][i].val);
			}
		}
	}
	cout << dp[m];

	/*以下是我自己想的一种把全部表列出来然后求结果的想法，这样虽然清晰但是占用的空间比较大*/
	//int res[101] = {};
	//int dp[1001] = {};
	//for (int k = 1; k <= groups; k++) {
	//	for (int i = 1; i <= list[k].size() - 1; i++) {
	//		for (int j = m; j >= 0; j--) {
	//			if (j >= list[k][i].weight)
	//				dp[j] = max(dp[j], dp[j - list[k][i - 1].weight] + list[k][i].val);
	//		}
	//	}
	//	res[k] = dp[m];
	//	memset(dp, 0, sizeof(dp));
	//}
	//int finalres = -1;
	//for (int i = 1; i <= groups; i++) {
	//	finalres = max(finalres, res[i]);
	//}
	//cout << finalres;
	return 0;
}