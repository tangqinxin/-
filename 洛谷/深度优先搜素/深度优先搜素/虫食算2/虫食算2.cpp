#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#pragma warning(disable: 4996)  
#define maxn 30
int n, flag[maxn];
char s[4][maxn];
bool use[maxn];
int id(char ch)//���ַ���ת��Ϊ���� 
{
	return ch - 'A' + 1;
}
void dfs(int x, int y, int t)//x�����У�y�����У�t�����λ 
{
	if (x == 0) //���ϵ��£����ҵ���x==0��ʾ�ѵ������һ�� 
	{
		if (t == 0)//���һ�в����н�λ�����������Ϊ��������ַ���������������ַ�����һλ 
		{
			for (int i = 1; i<n; i++) //������������������ 
				printf("%d ", flag[i]);//��� 
			printf("%d\n", flag[n]);//��� 
			exit(0);    //�൱��return  0;������� 
		}
		return;//���� 
	}
	for (int i = x - 1; i >= 1; i--) //��֦1 
	{
		int w1 = flag[id(s[1][i])];//w1��ʾ��һ���ַ������������ 
		int w2 = flag[id(s[2][i])];//w2��ʾ�ڶ����ַ������������ 
		int w3 = flag[id(s[3][i])];//w3��ʾ�������ַ������������ 
		if (w1 == -1 || w2 == -1 || w3 == -1) //������λ���ϻ�û����ֵ���ͷ��� 
			continue;
		if ((w1 + w2) % n != w3 && (w1 + w2 + 1) % n != w3)
			return;    //������۽�λ��񣬶�����������Ӧ��w3��˵���ַ�����ƥ�䣬ֱ��return ; 
	}
	if (flag[id(s[y][x])] == -1) ////������λ���ϻ�û����ֵ���ͽ��и�ֵ���� 
	{
		for (int i = n-1; i>=0; i--) //����ö�ٸ��� 
			if (!use[i]) //��������û���ù� 
			{
				if (y != 3) //�Ҳ������һ�� 
				{
					flag[id(s[y][x])] = i;//�ͽ����λ�ø���ֵ 
					use[i] = 1;//���������ù�
					dfs(x, y + 1, t);//����������һ�� 
					flag[id(s[y][x])] = -1;//��ԭ 
					use[i] = 0;//��ԭ 
				}
				else //��y==3ʱ 
				{
					int w = flag[id(s[1][x])] + flag[id(s[2][x])] + t;//�������������ǵĽ�λ 
					if (w%n != i)
						continue;
					use[i] = 1; flag[id(s[3][x])] = i;//��ֵ�����������ù� 
					dfs(x - 1, 1, w / n);//������һ�У���λ��Ҫ�ı� 
					use[i] = 0; flag[id(s[3][x])] = -1;//��ԭ 
				}
			}
	}
	else //������λ�����Ѿ�����ֵ�� 
	{
		if (y != 3) //�������� 
			dfs(x, y + 1, t);
		else
		{
			int w = flag[id(s[1][x])] + flag[id(s[2][x])] + t;
			if (w%n != flag[id(s[3][x])]) //��֦ 2
				return;
			dfs(x - 1, 1, w / n);//������һ�У���λ��Ҫ�ı� 
		}
	}
}
int main()
{
	scanf("%d", &n);//����n,����n���Ƶ�...... 
	for (int i = 1; i <= 3; i++)
		scanf("%s", s[i] + 1);//����3���ַ��� 
	memset(flag, -1, sizeof(flag));//������λ�ñ��Ϊδ��ֵ 
	dfs(n, 1, 0);//�����������������������дӵ�n�У���1�п�ʼ 
	return 0;//���� 
}