#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
struct obj {
	int v;
	int w;
};

int main() {
	int dp[30001];
	memset(dp, 0, sizeof(dp));
	int N, m;
	cin >> N >> m;
	obj list[26];
	for (int i = 1; i <= m; i++) {
		cin >> list[i].v >> list[i].w;
	}
	for (int i = 1; i <= m; i++) {
		for (int j = N; j >= 0; j--) {
			if (j >= list[i].v)
				dp[j] = max({ dp[j],dp[j - list[i].v] + list[i].v*list[i].w });
		}
	}
	cout << dp[N];
	return 0;
}







/*使用vector创建矩阵*/
//int main() {
//	int N, m;
//	cin >> N >> m;
//	obj list[26];
//	for (int i = 1; i <= m; i++) {
//		cin >> list[i].v >> list[i].w;
//	}
//	vector<vector<int>> dp(m + 1, vector<int>(N + 1));//dp[i][j]可以买前i种商品，恰好花j元
//	for (int i = 0; i <= N; i++) {
//		dp[0][i] = 0;
//	}
//	for (int i = 1; i <= m; i++) {
//		for (int j = 1; j <= N; j++) {
//			if (j >= list[i].v)
//				dp[i][j] = max({ dp[i - 1][j],dp[i - 1][j - list[i].v] + list[i].v*list[i].w });
//			else dp[i][j] = dp[i - 1][j];
//		}
//	}
//
//	cout<<dp[m][N];
//	return 0;
//}

/*  
//正常的解答
struct obj {
	int v;
	int w;
};

int main() {
	int dp[30001] = {0};
	obj list[30];
	int N, m;
	cin >> N >> m;
	for (int i = 1; i <= m; i++) {
		cin >> list[i].v >> list[i].w;
	}
	for (int i = 1; i <= m; i++) {
		for (int j = N; j >=0; j--) {
			if (j >= list[i].v)
				dp[j] = max(dp[j], dp[j - list[i].v] + list[i].v*list[i].w);
		}
	}
	cout << dp[N];
	return 0;
}
*/

/* 未经优化的0-1背包
int main() {
	int** dp = new int*[30];
	for (int i = 0; i < 30; i++) {
		dp[i] = new int[30001];
		memset(dp[i], 0, sizeof(int) * 30001);
	}

	obj list[30];
	int N, m;
	cin >> N >> m;
	for (int i = 1; i <= m; i++) {
		cin >> list[i].v >> list[i].w;
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j <= N; j++) {
			if (j >= list[i].v)
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - list[i].v] + list[i].v*list[i].w);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	cout << dp[m][N];
	for (int i = 0; i < 30; i++) {
		delete[]dp[i];
	}
	delete[]dp;

	return 0;
}
*/



/*
int main() {
	int dp[30001];
	int N, m;
	cin >> N >> m;
	obj list[26];
	for (int i = 1; i <= m; i++) {
		cin >> list[i].v >> list[i].w;
	}
	dp[0] = 0;
	memset(dp, 0, sizeof(dp));
	int tempmax=0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= m; j++) {
			int index = i - list[j].v;
			if (index>= 0) {
				dp[i]= max(dp[index] + list[j].v*list[j].w, dp[i]);
			}
		}
	}
	cout << dp[N];
	return 0;
}
*/