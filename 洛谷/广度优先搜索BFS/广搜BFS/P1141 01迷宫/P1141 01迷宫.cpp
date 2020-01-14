#include<iostream>
#include<queue>
#include<map>
#include<algorithm>
#include<cstring>
#define maxsize 1005
char mat[maxsize][maxsize];//输入矩阵
int origin[100005][2];//输入起点
int mark[maxsize][maxsize];//记录搜索过的点，防止反复搜索
int memry[maxsize][maxsize];//记忆化搜索索引
int ans[1000005];//记忆化结果结果记录
int dir[][2] = { {0,-1},{0,1},{1,0},{-1,0} };
int n, m;
int d = 0;
using namespace std;

struct node {
	int row;
	int col;
	node(int r,int c):row(r),col(c){}
};




bool path_ok(int currow, int curcol, int nextrow, int nextcol) {
	if (nextrow >= 1 && nextrow <= n&&nextcol >= 1 && nextcol <= n&&mat[currow][curcol] != mat[nextrow][nextcol]) {
			return mark[nextrow][nextcol] == 0;//不越界,不同元素的情况下可以访问该点
	}
	else {
		return false;
	}
}



int bfs(int row, int col) {
	queue<node> q;
	node start(row, col);
	q.push(start);
	int count = 0;
	mark[row][col] = 1;
	memry[row][col] = d;

	while (!q.empty()) {
		node tmp = q.front();
		q.pop();
		count++;

		for (int i = 0; i < 4; i++) {
			int nextrow = tmp.row + dir[i][0];
			int nextcol = tmp.col + dir[i][1];
			if (path_ok(tmp.row, tmp.col, nextrow, nextcol)) {
				node NewNode(nextrow, nextcol);
				mark[nextrow][nextcol] = 1;//访问过记为1，没访问过记为0
				q.push(NewNode);
				memry[nextrow][nextcol] = d;
			}
		}
	}

	return count;
}

int main() {
	cin >> n >> m;
	for (int row = 1; row <= n; row++) {
		for (int col = 1; col <= n; col++) {
			cin >> mat[row][col];
		}
	}

	for (int i = 0; i < m; i++) {
		cin >> origin[i][0] >> origin[i][1];
	}

	memset(memry, -1, sizeof(memry));//记忆化搜索

	for (int i = 0; i < m; i++) {
		int r = origin[i][0];
		int c = origin[i][1];
		if (memry[r][c]==-1) {//首先判断是否可以得到结果
			d++;
			ans[d]=bfs(r, c);
			cout << ans[d]<<endl;
		}
		else {
			cout << ans[memry[r][c]] << endl;
		}
	}

	return 0;
}