#include<iostream>
#include<queue>
#define maxsize 50
using namespace std;
int mat[maxsize][maxsize];//标记地图
int mark[maxsize][maxsize];//标记外部的染色
int n;
int dir[][2] = { { -1,0 },{ 1,0 },{ 0,1 },{ 0,-1 } };

struct node {
	int row;
	int col;
};

bool judge(node p) {
	int row = p.row;
	int col = p.col;
	if (row<0 || col<0 || row>n + 1 || col>n + 1)return false;
	if (mark[row][col] == 1 || mat[row][col] == 1)return false;
	return true;
}


void BFS(int row, int col) {
	node s;
	s.row = row;
	s.col = col;
	queue<node> q;
	q.push(s);
	while (!q.empty()) {
		node temp = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int newrow = temp.row + dir[i][0];
			int newcol = temp.col + dir[i][1];
			node newtemp;
			newtemp.row = newrow;
			newtemp.col = newcol;
			if (judge(newtemp)) {
				mark[newtemp.row][newtemp.col] = 1;//标记为已经访问过,染色了
				q.push(newtemp);
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> mat[i][j];
		}
	}
	BFS(0, 0);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (mat[i][j] == 0 && mark[i][j] == 0) {
				cout << "2 ";
			}
			else if (mat[i][j] == 0 && mark[i][j] == 1) {
				cout << "0 ";
			}
			else if (mat[i][j] == 1) {
				cout << "1 ";
			}
		}
		cout << endl;
	}
	return 0;
}