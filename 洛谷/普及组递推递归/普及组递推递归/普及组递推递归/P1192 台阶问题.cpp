#include<iostream>
#include<cstring>
using namespace std;
int n, k;
int ans;
#define MOD 100003
#define maxsize 100005
int mark[maxsize];//mark[i]表示从第i级到第n级有多少方法


//暴力搜
void dfs(int cur) {
	if (cur > n) {
		return;
	}
	if (cur == n) {
		ans++;
		return;
	}
	for (int i = 1; i <= k; i++) {
		dfs(cur + i);
	}
}

//打表搜,记忆化
int dfs2(int cur) {
	//返回从cur到n有多少种方法
	if (mark[cur] != -1) {
		return mark[cur];
	}
	if (cur > n) {
		return 0;
	}
	if (cur == n) {
		return 1;
	}
	//如果没有记录，那么就要计算结果
	int res=0;
	for (int i = 1; i <= k; i++) {
		if (cur + i <= n) {
			res += dfs2(cur + i);
		}
		if (cur + i > n)break;
	}
	mark[cur] = res%MOD;
	return mark[cur];
}

int main() {
	cin >> n >> k;
	//dfs(0);//暴力搜
	memset(mark, -1, sizeof(mark));
	mark[n] = 1;
	for (int i = n; i >= 0; i--) {
		dfs2(i);
	}
	ans = mark[0]%MOD;
	cout << ans;
	return 0;
}