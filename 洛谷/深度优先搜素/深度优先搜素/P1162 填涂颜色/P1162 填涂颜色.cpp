#include<iostream>
#define maxsize 50
using namespace std;
int mat[maxsize][maxsize];//��ǵ�ͼ
int mark[maxsize][maxsize];//����ⲿ��Ⱦɫ
int n;
int dir[][2] = { {-1,0},{1,0},{0,1},{0,-1} };

void dfs(int row, int col) {
	if ( row<0 || col < 0||row>n+1||col>n+1||mat[row][col]==1||mark[row][col]==1) {
		return;//ע�⣬������˵�ͼ�ϰ����м�֦��mark��ǵ�ҲӦ�ý��м�֦�����������ظ�����
	}
	mark[row][col] = 1;
	for (int i = 0; i < 4; i++) {
		int newrow = row + dir[i][0];
		int newcol = col + dir[i][1];
		dfs(newrow, newcol);
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> mat[i][j];
		}
	}
	dfs(0, 0);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (mat[i][j] != 1 && mark[i][j] != 1) {
				cout << "2 ";
			}
			else if (mat[i][j] != 1 && mark[i][j] == 1) {
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