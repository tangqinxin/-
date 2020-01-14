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
//��֦˼·������ֻѡ����Щ�ֲ����ĵ����dfs
int mark[maxsize][maxsize];
int res = 0;
int r, c;

void PreProcess(int r, int c) {
	//����Ԥ��������ҵ��ֲ����ĵ�
	for (int row = 1; row <= r; row++) {
		for (int col = 1; col <= c; col++) {
			int flag = 1;
			for (int i = 0; i < 4; i++) {
				int newrow = row + dir[i][0];
				int newcol = col + dir[i][1];
				if (newrow > r || newrow<1 || newcol>c || newcol < 1) {
					continue;//���Խ���ˣ��Ͳ���������龰
				}
				if (mat[row][col] < mat[newrow][newcol]) {
					flag = 0;//���û��Խ�磬�ж��Ƿ����ΧС��С�Ļ���û��dfs�ı�Ҫ��
					break;
				}
			}
			mark[row][col] = flag;
		}
	}
}

void dfs(int row, int col,int step) {
	//��[row,col]��������ѣ��õ�������󳤶ȣ����Ƚ�
	for (int i = 0; i < 4; i++) {
		int newrow = row + dir[i][0];
		int newcol = col + dir[i][1];
		if (newrow > r || newrow<1 || newcol>c || newcol < 1) {
			continue;//���Խ���ˣ��Ͳ���������龰
		}
		if (mat[row][col] > mat[newrow][newcol]) {
			dfs(newrow, newcol, step + 1);//��С�Ļ���������
		}
	}
	res = max(res, step);//���׽�β֮���޷������ˣ���ֱ�ӱȽϽ��
}

int dfs2(int row, int col) {
	//��[row,col]��������ѣ��õ�һ������ֵ����mark����¼�Ƿ��Ѿ����ֵ
	if (mark[row][col] != 0) {
		return mark[row][col];//����Ѿ����һ�Σ�ֱ��ʹ�ü��仯������ֵ
	}
	mark[row][col] = 1;//��ǰ����Ҳ�㣬��˳�ʼ��Ϊ1
	for (int i = 0; i < 4; i++) {
		int newrow = row + dir[i][0];
		int newcol = col + dir[i][1];
		if (newrow <= r&&newrow >= 1 && newcol <= c&&newcol >= 1&&mat[row][col]>mat[newrow][newcol]) {//��Խ���������ݶȵ������
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
	//����1
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