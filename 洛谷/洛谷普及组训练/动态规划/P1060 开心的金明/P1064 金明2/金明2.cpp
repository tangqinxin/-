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
		scanf("%d%d%d", &a[i].v, &a[i].p, &a[i].q);//�����Ķ���
		if (a[i].q)//��������Ʒ�Ǹ���
		{
			t[a[i].q]++;
			pat[a[i].q][t[a[i].q]].v = a[i].v;
			pat[a[i].q][t[a[i].q]].p = a[i].p;
			pat[a[i].q][t[a[i].q]].q = a[i].q;//����������Ӧ�������ķ�����
		}
	}
	for (int i = 1; i <= m; i++)//01��������
	{
		if (t[i])//�����ǰ��ƷΪ����
		{
			memset(f, -1, sizeof(f));//ǡ�ñ����Ĵ���-1��ʾ��ǡ��ȡ���˼�ֵ
			f[0] = 0;//ǡ�ñ����Ĵ���
			for (int j = 1; j <= t[i]; j++)
				for (int k = n - a[i].v; k >= pat[i][j].v; k--)
					if (f[k]<f[k - pat[i][j].v] + pat[i][j].v*pat[i][j].p && f[k - pat[i][j].v] != -1)//ǡ�ñ������ж�
						f[k] = f[k - pat[i][j].v] + pat[i][j].v*pat[i][j].p;//��ƽ����01״̬ת��
			for (int j = 0; j <= n - a[i].v; j++)
				if (f[j] != -1)//ǡ�ñ������жϣ����ָ��������������
				{
					cnt[i]++;
					V[i][cnt[i]] = j + a[i].v;
					P[i][cnt[i]] = f[j] + a[i].v*a[i].p;//�Ѵ������������i�ķ����У�Ϊ���鱳�����ô���
				}
		}
		if (!a[i].q)//ֻ������
		{
			cnt[i]++;
			V[i][cnt[i]] = a[i].v;
			P[i][cnt[i]] = a[i].v*a[i].p;//�洢
		}
	}
	memset(f, 0, sizeof(f));
	for (int i = 1; i <= m; i++)
		for (int j = n; j >= 0; j--)
			for (int k = 1; k <= cnt[i]; k++)
				if (j >= V[i][k])
					f[j] = max(f[j], f[j - V[i][k]] + P[i][k]);//���鱳���ļ���
	for (int i = 0; i <= n; i++)
		ans = max(ans, f[i]);
	printf("%d", ans);//���
	return 0;
}