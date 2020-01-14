#include<iostream>
#include<queue>
#include<map>
#include<algorithm>
#include<cstring>
#define maxsize 1005
char mat[maxsize][maxsize];//�������
int origin[100005][2];//�������
int mark[maxsize][maxsize];//��¼�������ĵ㣬��ֹ��������
int memry[maxsize][maxsize];//���仯��������
int ans[1000005];//���仯��������¼
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
			return mark[nextrow][nextcol] == 0;//��Խ��,��ͬԪ�ص�����¿��Է��ʸõ�
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
				mark[nextrow][nextcol] = 1;//���ʹ���Ϊ1��û���ʹ���Ϊ0
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

	memset(memry, -1, sizeof(memry));//���仯����

	for (int i = 0; i < m; i++) {
		int r = origin[i][0];
		int c = origin[i][1];
		if (memry[r][c]==-1) {//�����ж��Ƿ���Եõ����
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