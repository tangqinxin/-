#include<iostream>
#include<algorithm>
#include<climits>
#include<vector>
using namespace std;
#define maxsize 105
int mat[maxsize][maxsize];
int dir[][2] = {
	{-1,0},
	{1,0},
	{0,-1},
	{0,1}
};
//剪枝思路，我们只选择哪些局部最大的点进行dfs
int mark[maxsize][maxsize];
int res = 0;
int r, c;

void PreProcess(int r, int c) {
	//建立预处理矩阵，找到局部最大的点
	for (int row = 1; row <= r; row++) {
		for (int col = 1; col <= c; col++) {
			int flag = 1;
			for (int i = 0; i < 4; i++) {
				int newrow = row + dir[i][0];
				int newcol = col + dir[i][1];
				if (newrow > r || newrow<1 || newcol>c || newcol < 1) {
					continue;//如果越界了，就不讨论这个情景
				}
				if (mat[row][col] < mat[newrow][newcol]) {
					flag = 0;//如果没有越界，判断是否比周围小，小的话就没有dfs的必要了
					break;
				}
			}
			mark[row][col] = flag;
		}
	}
}

void dfs(int row, int col,int step) {
	//对[row,col]点进行深搜，得到它的最大长度，并比较
	for (int i = 0; i < 4; i++) {
		int newrow = row + dir[i][0];
		int newcol = col + dir[i][1];
		if (newrow > r || newrow<1 || newcol>c || newcol < 1) {
			continue;//如果越界了，就不讨论这个情景
		}
		if (mat[row][col] > mat[newrow][newcol]) {
			dfs(newrow, newcol, step + 1);//更小的话可以深搜
		}
	}
	res = max(res, step);//到底结尾之后无法深搜了，就直接比较结果
}

int dfs2(int row, int col) {
	//对[row,col]点进行深搜，得到一个返回值。用mark来记录是否已经求得值
	if (mark[row][col] != 0) {
		return mark[row][col];//如果已经求过一次，直接使用记忆化搜索的值
	}
	mark[row][col] = 1;//当前格子也算，因此初始化为1
	for (int i = 0; i < 4; i++) {
		int newrow = row + dir[i][0];
		int newcol = col + dir[i][1];
		if (newrow <= r&&newrow >= 1 && newcol <= c&&newcol >= 1&&mat[row][col]>mat[newrow][newcol]) {//不越界且满足梯度的情况下
			int val=dfs2(newrow, newcol);
			mark[row][col] = max(mark[row][col], mark[newrow][newcol] + 1);
		}
	}

	return mark[row][col];
}

int main() {
	cin >> r >> c;
	fill(mat[0], mat[0] + maxsize*maxsize, INT_MAX);
	for (int row = 1; row <= r; row++) {
		for (int col = 1; col <= c; col++) {
			cin >> mat[row][col];
		}
	}
	//方法1
	//PreProcess(r, c);
	//for (int row = 1; row <= r; row++) {
	//	for (int col = 1; col <= c; col++) {
	//		if (mark[row][col] == 1) {
	//			dfs(row, col, 1);
	//		}
	//	}
	//}
	for (int row = 1; row <= r; row++) {
		for (int col = 1; col <= c; col++) {
			res=max(res,dfs2(row, col));
		}
	}


	cout << res;
	return 0;
}