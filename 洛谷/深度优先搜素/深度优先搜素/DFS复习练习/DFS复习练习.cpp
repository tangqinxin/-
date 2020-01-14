//单词接龙复习
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#define maxsize 105
using namespace std;

char mat[maxsize][maxsize];
int mark[maxsize][maxsize];
int dir_vec[][2] = { {0,1},{0,-1},{1,0},{-1,0}, {-1,-1},{-1,1},{1,1},{1,-1} };
struct point {
	int row;
	int col;
	point(int r,int c):row(r),col(c){}
};
vector<point> path;
int n;
string obj = "yizhong";

void dfs(int row, int col, int dir,int curlen) {
	if (row < 0 || col < 0) {
		path.clear();
		return;
	}
	//curlen的作用类似于记录当前的path中已经有多少个点了
	if (curlen==6&&mat[row][col]==obj[obj.size()-1]) {
		point tmppoint(row, col);
		path.push_back(tmppoint);//将最后一个点加入
		for (int i = 0; i < 7; i++) {
			int markrow = path[i].row;
			int markcol = path[i].col;
			mark[markrow][markcol] = 1;
		}
		path.clear();
		return;
	}
	if (mat[row][col] == obj[curlen]) {
		int newrow = row + dir_vec[dir][0];
		int newcol = col + dir_vec[dir][1];
		point tmppoint(row, col);
		path.push_back(tmppoint);
		dfs(newrow, newcol, dir, curlen + 1);
	}
	else if (mat[row][col] != obj[curlen]) {
		//不符合，则清空整个path
		path.clear();
		return;
	}
}


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> mat[i];
	}
	for (int row = 0; row < n; row++) {
		for (int col = 0; col < n; col++) {
			if (mat[row][col] == obj[0]) {
				for (int k = 0; k < 8; k++) {
					int newrow = row + dir_vec[k][0];
					int newcol = col + dir_vec[k][1];
					if (newrow>=0&&newcol>=0&&mat[newrow][newcol] == obj[1]) {
						dfs(row, col, k, 0);
					}
				}
			}
		}
	}

	for (int row = 0; row < n; row++) {
		for (int col = 0; col < n; col++) {
			if (mark[row][col] == 1) {
				cout << mat[row][col];
			}
			else if (mark[row][col] == 0) {
				cout << '*';
			}
		}
		cout << endl;
	}


	return 0;
}