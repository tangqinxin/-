#include<iostream>
#define maxsize 10
using namespace std;

int mat[maxsize][maxsize];
int bar[maxsize][maxsize];
int rowbar[100];
int colbar[100];
int N, M, T;
int sx, sy, fx, fy;
int total = 0;

int dir[][2] = { {-1,0},{1,0},{0,1},{0,-1} };

void VisitPoint(int row, int col) {
	mat[row][col] = 1;
}

void SetBar(int row, int col) {
	bar[row][col] = 1;
}

void CleanMark(int row, int col) {
	mat[row][col] = 0;
}

void DFS(int row, int col) {
	if (row == fy&&col == fx) {
		total++;
		return;
	}
	for (int k = 0; k < 4; k++) {
		int NextRow = row + dir[k][0];
		int Nextcol = col + dir[k][1];
		if (mat[NextRow][Nextcol] != 1&&bar[NextRow][Nextcol]!=1) {
			VisitPoint(row, col);
			DFS(NextRow, Nextcol);
			CleanMark(row, col);
		}
	}
}


int main() {
	cin >> N >> M >> T;
	cin >> sx >> sy >> fx >> fy;
	for (int i = 0; i < T; i++) {
		cin >> colbar[i] >> rowbar[i];
		SetBar(rowbar[i], colbar[i]);
	}
	for (int i = 0; i <= M + 1; i++) {
		SetBar(0, i);//第0行初始化
		SetBar(N + 1, i);//第N+1行初始化
	}
	for (int i = 0; i <= N + 1; i++) {
		SetBar(i, 0);
		SetBar(i, M + 1);
	}

	DFS(sy, sx);
	cout << total;
	return 0;
}