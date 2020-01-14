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
int id(char ch)//将字符串转换为数字 
{
	return ch - 'A' + 1;
}
void dfs(int x, int y, int t)//x代表列，y代表行，t代表进位 
{
	if (x == 0) //从上到下，从右到左，x==0表示搜到了最后一列 
	{
		if (t == 0)//最后一列不能有进位，如果进了以为则第三个字符串会比其他两个字符串长一位 
		{
			for (int i = 1; i<n; i++) //如果满足条件，就输出 
				printf("%d ", flag[i]);//输出 
			printf("%d\n", flag[n]);//输出 
			exit(0);    //相当于return  0;程序结束 
		}
		return;//返回 
	}
	for (int i = x - 1; i >= 1; i--) //剪枝1 
	{
		int w1 = flag[id(s[1][i])];//w1表示第一行字符串代表的数字 
		int w2 = flag[id(s[2][i])];//w2表示第二行字符串代表的数字 
		int w3 = flag[id(s[3][i])];//w3表示第三行字符串代表的数字 
		if (w1 == -1 || w2 == -1 || w3 == -1) //如果这个位置上还没被赋值，就返回 
			continue;
		if ((w1 + w2) % n != w3 && (w1 + w2 + 1) % n != w3)
			return;    //如果无论进位与否，都不能整除对应的w3就说明字符串不匹配，直接return ; 
	}
	if (flag[id(s[y][x])] == -1) ////如果这个位置上还没被赋值，就进行赋值操作 
	{
		for (int i = n-1; i>=0; i--) //倒着枚举更快 
			if (!use[i]) //如果这个数没有用过 
			{
				if (y != 3) //且不是最后一行 
				{
					flag[id(s[y][x])] = i;//就将这个位置赋上值 
					use[i] = 1;//标记这个数用过
					dfs(x, y + 1, t);//继续搜索下一行 
					flag[id(s[y][x])] = -1;//还原 
					use[i] = 0;//还原 
				}
				else //当y==3时 
				{
					int w = flag[id(s[1][x])] + flag[id(s[2][x])] + t;//两个数加上它们的进位 
					if (w%n != i)
						continue;
					use[i] = 1; flag[id(s[3][x])] = i;//赋值，标记这个数用过 
					dfs(x - 1, 1, w / n);//搜索下一列，进位需要改变 
					use[i] = 0; flag[id(s[3][x])] = -1;//还原 
				}
			}
	}
	else //如果这个位置上已经被赋值了 
	{
		if (y != 3) //继续搜索 
			dfs(x, y + 1, t);
		else
		{
			int w = flag[id(s[1][x])] + flag[id(s[2][x])] + t;
			if (w%n != flag[id(s[3][x])]) //剪枝 2
				return;
			dfs(x - 1, 1, w / n);//搜索下一列，进位需要改变 
		}
	}
}
int main()
{
	scanf("%d", &n);//读入n,代表n进制等...... 
	for (int i = 1; i <= 3; i++)
		scanf("%s", s[i] + 1);//读入3行字符串 
	memset(flag, -1, sizeof(flag));//将所有位置标记为未赋值 
	dfs(n, 1, 0);//从右往左，上往下搜索，所有从第n列，第1行开始 
	return 0;//结束 
}