#include<iostream>
#include<algorithm>
using namespace std;
#define maxsize 15

struct node{
	int rowindex;
	int zerocnt;
};
int mat[maxsize][maxsize];//�洢��ʼ�����ֵ
int rowmark[maxsize][maxsize];//rowrark[row][i]==1��ʾ��row�У�����i�Ѿ���ʹ�ù�
int colmark[maxsize][maxsize];//colmark[col][i]==1��ʾ��col�У�����i�Ѿ���ʹ�ù�
int blockmark[maxsize][maxsize];//nineblock[ind][i]==1��ʾ��ind���Ź�������i�Ѿ���ʹ�ù�
int maxres = 0;//���
bool flag = 0;//�Ƿ��������Ĵ�
node dfsrow[maxsize];//��¼���е�����˳��dfsrow[1]��ʾ��һ���������е�0�����ٵ�

struct Point {
	int row;
	int col;
};
Point points[100];

bool cmp(node a, node b) {
	return a.zerocnt < b.zerocnt;
}


int loc2blkind(int row, int col) {
	//����[row,col]�����ض�Ӧ��block�±�
	if (row <= 3) {
		if (col <= 3)return 1;
		if (col > 3 && col <= 6) return 2;
		if (col > 6 && col <= 9) return 3;
	}
	if (row > 3 && row <= 6) {
		if (col <= 3)return 4;
		if (col > 3 && col <= 6)return 5;
		if (col > 6 && col <= 9)return 6;
	}
	if (row > 6 && row <= 9) {
		if (col <= 3)return 7;
		if (col > 3 && col <= 6)return 8;
		if (col > 6 && col <= 9)return 9;
	}
}

//�����֦Ҫ�㣬��0�ٵĵط��������ѱ�������Ѹ���
void getdata() {
	for (int row = 1; row <= 9; row++) {
		dfsrow[row].rowindex = row;
		dfsrow[row].zerocnt = 0;
		for (int col = 1; col <= 9; col++) {
			cin >> mat[row][col];
			if (mat[row][col] != 0) {
				int num = mat[row][col];
				int blkind = loc2blkind(row, col);
				rowmark[row][num] = 1;
				colmark[col][num] = 1;
				blockmark[blkind][num] = 1;//�����ǰ��ͳ�Ƶ㲻Ϊ0������ϱ��
				//����һ��Ҫע�⣬�˴��ı��һ����������Ĺ����оʹ��ϱ�ǣ�Ҳ����
				//һ��ʼ�ʹ��ϱ�ǣ����������������У����һ��ʼ����0����ô���ܻ����
				//ͬһ�д���2��1�����߶��1����������³���
			}
			if (mat[row][col] == 0) {
				dfsrow[row].zerocnt = dfsrow[row].zerocnt + 1;
			}
		}
	}
	sort(dfsrow + 1, dfsrow + 10, cmp);
}


int calsum(int row, int col) {
	//�ο����еĴ��룬���ִ�����������������ܼ�
	if (row == 1 || row == 9 || col == 1 || col == 9)return mat[row][col] * 6;
	if (row == 2 || row == 8 || col == 2 || col == 8)return mat[row][col] * 7;
	if (row == 3 || row == 7 || col == 3 || col == 7)return mat[row][col] * 8;
	if (row == 4 || row == 6 || col == 4 || col == 6)return mat[row][col] * 9;
	else return mat[row][col]*10;
}

void dfs(int pcnt,int cursum) {
	//pcnt��ʾ����ͳ�Ƶ�pcnt����
	if (pcnt == 82) {
		maxres = max(maxres, cursum);
		flag = 1;
		return;
	}

	Point curpoint = points[pcnt];//��ǰҪͳ�Ƶĵ�
	int row = curpoint.row;
	int col = curpoint.col;
	int blkind = loc2blkind(row, col);

	if (mat[row][col] != 0) {//�����ǰ��ͳ�Ƶ㲻Ϊ0������ϱ�ǣ����֮���������
		int addval = calsum(row, col);
		dfs(pcnt + 1, cursum + addval);
	}
	else if (mat[row][col] == 0) {//�����ǰ��ͳ�Ƶ�Ϊ0����ô����Ҫö��
		for (int i = 1; i <= 9; i++) {//ö������
			if (rowmark[row][i] != 1 && colmark[col][i] != 1 && blockmark[blkind][i] != 1) {

				rowmark[row][i] = 1;
				colmark[col][i] = 1;
				blockmark[blkind][i] = 1;
				mat[row][col] = i;//���

				int addval = calsum(row, col);
				dfs(pcnt + 1, cursum + addval);//���ﾡ���üӷ�

				rowmark[row][i] = 0;
				colmark[col][i] = 0;
				blockmark[blkind][i] = 0;
				mat[row][col] = 0;//������ǣ�����
			}
		}
	}
}


int main() {
	getdata();
	//������˳��
	int cnt = 1;
	for (int row = 1; row <= 9; row++) {
		for (int col = 1; col <= 9; col++) {
			points[cnt].row = dfsrow[row].rowindex;
			points[cnt].col = col;
			cnt++;
		}
	}

	dfs(1,0);

	if (flag == 0) {
		cout << "-1" << endl;
	}
	else if (flag != 0) {
		cout << maxres << endl;
	}

	return 0;
}