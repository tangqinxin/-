#include<iostream>
#include<climits>
#include<algorithm>
#include<queue>
#define maxsize 405
using namespace std;
int mat[maxsize][maxsize];
int n, m;
int srow, scol;

int rowcol_change[][2] = {
	{-1,2},//上右
	{-2,1},
	{-1,-2},//上左
	{-2,-1},
	{2,1},//下右
	{1,2},
	{2,-1},//下左
	{1,-2}
};

struct node {
	int row;
	int col;
	int step;
};

bool pace(node tmp, int k) {
	//判断tmp状态能否按照k方向前进
	int nextrow = tmp.row + rowcol_change[k][0];
	int nextcol = tmp.col + rowcol_change[k][1];
	if (nextrow >= 1 && nextrow <= n&&nextcol >= 1 && nextcol <= m) {//越界判断
		return true;
	}
	return false;
}

void bfs(int row, int col) {
	node start;
	start.row = row;
	start.col = col;
	start.step = 0;
	mat[row][col] = 0;
	queue<node> q;
	q.push(start);

	while (!q.empty()) {
		node tmp = q.front();
		q.pop();

		for (int i = 0; i < 8; i++) {
			if (pace(tmp, i)) {//如果当前方向可以到达那个点
				int nextrow = tmp.row + rowcol_change[i][0];
				int nextcol = tmp.col + rowcol_change[i][1];
				if (tmp.step + 1 < mat[nextrow][nextcol]) {//如果这个走法可以更新
					mat[nextrow][nextcol] = tmp.step + 1;
					node tmp2;
					tmp2.row = nextrow;
					tmp2.col = nextcol;
					tmp2.step = tmp.step + 1;
					q.push(tmp2);
				}
			}
		}
	}
}

void disp() {
	for (int row = 1; row <= n; row++) {
		for (int col = 1; col <= m; col++) {
			if (mat[row][col] == INT_MAX) {
				printf("%-5d", -1);
			}
			else {
				printf("%-5d", mat[row][col]);
			}
		}
		cout << endl;
	}
}

int main() {
	cin >> n >> m;
	cin >> srow >> scol;
	fill(mat[0], mat[0]+maxsize*maxsize, INT_MAX);
	bfs(srow, scol);
	disp();
	return 0;
}