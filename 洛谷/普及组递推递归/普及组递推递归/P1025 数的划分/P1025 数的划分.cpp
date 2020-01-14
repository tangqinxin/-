//#include<iostream>
//#include<algorithm>
//using namespace std;
//int n, k;
//int cnt = 0;
//
//void dfs(int last,int sum,int cur) {
//	if (cur == k) {//cur==k就到尽头了，直接判断sum就知道是否可行
//		if (sum == n) {
//			cnt++;
//		}
//		return;
//	}
//	//if (last*(k-cur)+sum>n) {
//	//	return;//剪枝，如果之后的都取最小值还是比n大，那么不可能
//	//}
//	for (int i = last; i*(k-cur)+sum <= n; i++) {//典型的组合性剪枝，防止组合重复因此要递增枚举，i从last开始枚举保证递增
//		dfs(i, sum + i, cur + 1);
//	}
//}
//
//int main() {
//	cin >> n >> k;
//	dfs(1, 0, 0);
//	cout << cnt;
//	return 0;
//}


#include<iostream>
using namespace std;
int n, k;//将整数n分成k份 
int f[205][10];//f[i][j]为把i分为j个数的分法 
int main()
{
	cin >> n >> k;
	f[0][0] = 1;//初始化 
	for (int t = 1; t <= n; t++)//分出来的整块的大小 
		for (int i = t; i <= n; i++)//整个一块的大小 
			for (int j = 1; j <= k; j++)//分的段数 
				f[i][j] += f[i - t][j - 1];
	cout << f[n][k];//输出将整数n分成k份的分法 
	return 0;
}