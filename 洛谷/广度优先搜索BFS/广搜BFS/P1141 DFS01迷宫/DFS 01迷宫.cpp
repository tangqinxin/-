#include<iostream>
#include<cstring>
using namespace std;
#define maxsize 1005
char mat[maxsize][maxsize];
int mark[maxsize][maxsize];
int memry[maxsize][maxsize];
int origin[100005][2];//�������
int dir[][2] = { { 0,-1 },{ 0,1 },{ 1,0 },{ -1,0 } };
int ans[1000005];//���仯��������¼
int total = 0;
int n, m;
int d;


bool path_ok(int currow, int curcol, int newrow, int newcol) {
	if (newrow >= 1 && newrow <= n&&newcol >= 1 && newcol <= n&&mark[newrow][newcol] != 1) {
		return mat[currow][curcol] != mat[newrow][newcol];//��Խ�粻��������²����
	}
	else {
		return false;
	}
}

void dfs(int row, int col) {
	if (row<1 || row>n || col<1 || col>n || mark[row][col] == 1) {
		return;//Խ������Ѿ����ʹ��ͷ���
	}
	total++;
	mark[row][col] = 1;//���Ϊ�Ѿ����ʹ�,֮����������ͼ
	memry[row][col] = d;
	for (int i = 0; i < 4; i++) {
		int newrow = row + dir[i][0];
		int newcol = col + dir[i][1];
		if (path_ok(row, col, newrow, newcol)) {
			dfs(newrow, newcol);//���ⲻ��Ҫ����������
		}
	}

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
	memset(memry, -1, sizeof(memry));

	for (int i = 0; i < m; i++) {
		int r = origin[i][0];
		int c = origin[i][1];
		if (memry[r][c] == -1) {//�����ж��Ƿ���Եõ����
			d++;
			total = 0;
			dfs(r, c);
			ans[d] = total;
			cout << ans[d] << endl;
		}
		else {
			cout << ans[memry[r][c]] << endl;
		}
	}
	return 0;
}