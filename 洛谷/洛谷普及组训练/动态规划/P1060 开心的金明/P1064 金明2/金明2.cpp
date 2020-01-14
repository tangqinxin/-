#include <cstdio>
#include <cstring>
#include <algorithm>
#pragma warning(disable: 4996)  
using namespace std;
struct cas
{
	int v, p, q;
}a[60], pat[60][60];
int n, m, t[60], V[60][10], P[60][10], cnt[60], f[32000], ans;
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &a[i].v, &a[i].p, &a[i].q);//正常的读入
		if (a[i].q)//如果这个物品是附件
		{
			t[a[i].q]++;
			pat[a[i].q][t[a[i].q]].v = a[i].v;
			pat[a[i].q][t[a[i].q]].p = a[i].p;
			pat[a[i].q][t[a[i].q]].q = a[i].q;//把它存在相应的主件的分组中
		}
	}
	for (int i = 1; i <= m; i++)//01背包处理
	{
		if (t[i])//如果当前物品为主件
		{
			memset(f, -1, sizeof(f));//恰好背包的处理，-1表示不恰好取到此价值
			f[0] = 0;//恰好背包的处理
			for (int j = 1; j <= t[i]; j++)
				for (int k = n - a[i].v; k >= pat[i][j].v; k--)
					if (f[k]<f[k - pat[i][j].v] + pat[i][j].v*pat[i][j].p && f[k - pat[i][j].v] != -1)//恰好背包的判断
						f[k] = f[k - pat[i][j].v] + pat[i][j].v*pat[i][j].p;//很平常的01状态转移
			for (int j = 0; j <= n - a[i].v; j++)
				if (f[j] != -1)//恰好背包的判断，这种附件组合满足题意
				{
					cnt[i]++;
					V[i][cnt[i]] = j + a[i].v;
					P[i][cnt[i]] = f[j] + a[i].v*a[i].p;//把此情况存在主件i的分组中，为分组背包做好处理
				}
		}
		if (!a[i].q)//只买主件
		{
			cnt[i]++;
			V[i][cnt[i]] = a[i].v;
			P[i][cnt[i]] = a[i].v*a[i].p;//存储
		}
	}
	memset(f, 0, sizeof(f));
	for (int i = 1; i <= m; i++)
		for (int j = n; j >= 0; j--)
			for (int k = 1; k <= cnt[i]; k++)
				if (j >= V[i][k])
					f[j] = max(f[j], f[j - V[i][k]] + P[i][k]);//分组背包的计算
	for (int i = 0; i <= n; i++)
		ans = max(ans, f[i]);
	printf("%d", ans);//输出
	return 0;
}