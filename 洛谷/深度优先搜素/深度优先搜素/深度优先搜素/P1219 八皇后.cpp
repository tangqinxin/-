#include<iostream>
using namespace std;

int ans[100];
int column[100];
int rightupleftdown[100];
int leftuprightdown[100];
int n;
int total = 0;
int NumOfSol = 0;

void DispAns() {
	//打印结果
	if (total < 3) {
		for (int i = 1; i <= n; i++) {
			cout << ans[i] << " ";
		}
		cout << endl;
	}
	total++;
}

bool check(int row, int col) {
	//检查row行column列是否可以作为一个答案
	bool ColumnIsOk, RupLdown, LupRdown;
	ColumnIsOk = RupLdown = LupRdown = false;
	if (column[col] == 0)ColumnIsOk = true;
	if (rightupleftdown[row+col] == 0)RupLdown = true;
	if (leftuprightdown[row - col+n] == 0)LupRdown = true;
	return ColumnIsOk&&RupLdown&&LupRdown;
}

void Mark(int row, int col) {
	//添加标记
	column[col] = 1;
	rightupleftdown[row + col] = 1;
	leftuprightdown[row-col+n] = 1;
}

void CleanMark(int row, int col) {
	//清除标记
	column[col] = 0;
	rightupleftdown[row + col] = 0;
	leftuprightdown[row - col + n] = 0;
}

void DFS(int row) {
	//part1 判断是否到达搜索尾部
	if (row > n) {
		DispAns();
		NumOfSol++;
		return;
	}

	//part2 判断当前节点的周围
	for (int j = 1; j <= n; j++) {
		if (check(row, j)) {//[row,j]可以放皇后
			ans[row] = j;//记录答案
			Mark(row, j);//标记
			DFS(row + 1);//深一层搜索
			CleanMark(row, j);//从深一层出来，清除标记
		}
	}
}


int main() {
	cin >> n;
	DFS(1);
	cout << NumOfSol;
	return 0;
}