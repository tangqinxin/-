#include<iostream>
#include<climits>
#include<algorithm>
#include<cstring>
#define LL long long
#define maxsize 100000
using namespace std;
struct obj {
	LL a, b, c;
}list[55];

LL dp[100005] = {};//定义dp[i][j]为考虑前i种石材，经过j时刻后的最大美味度

bool cmp(obj p, obj q) {
	return (LL)p.b*(LL)q.c > (LL)p.c*(LL)q.b;//满足该方程返回true，不换顺序
}

int main() {
	int T,n;
	cin >>T>>n;

	for (int i = 1; i <= n; i++) {
		cin >> list[i].a ;
	}
	for (int i = 1; i <= n; i++) {
		cin >> list[i].b;
	}
	for (int i = 1; i <= n; i++) {
		cin >> list[i].c;
	}

	sort(list+1, list +n+1, cmp);
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = T; j >=0; j--) {
			if (j >= list[i].c&&dp[j - list[i].c] != -1) {
				dp[j] = max(dp[j], dp[j - list[i].c] + list[i].a - j*list[i].b);
			}
		}
	}
	LL res = 0;
	for (int i = 0; i <= T; i++) {
		res = max(res, dp[i]);
	}
	cout << res;
	return 0;
}