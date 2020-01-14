#include<iostream>
#include<algorithm>
using namespace std;
#define maxsize 15

struct node{
	int rowindex;
	int zerocnt;
};
int mat[maxsize][maxsize];//存储初始矩阵的值
int rowmark[maxsize][maxsize];//rowrark[row][i]==1表示第row行，数字i已经被使用过
int colmark[maxsize][maxsize];//colmark[col][i]==1表示第col行，数字i已经被使用过
int blockmark[maxsize][maxsize];//nineblock[ind][i]==1表示第ind个九宫，数字i已经被使用过
int maxres = 0;//结果
bool flag = 0;//是否存在满足的答案
node dfsrow[maxsize];//记录了行的搜索顺序，dfsrow[1]表示第一个搜索的行的0是最少的

struct Point {
	int row;
	int col;
};
Point points[100];

bool cmp(node a, node b) {
	return a.zerocnt < b.zerocnt;
}


int loc2blkind(int row, int col) {
	//输入[row,col]，返回对应的block下标
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

//本题剪枝要点，从0少的地方进行深搜比随机乱搜更快
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
				blockmark[blkind][num] = 1;//如果当前的统计点不为0，则打上标记
				//这里一定要注意，此处的标记一定是在输入的过程中就打上标记，也就是
				//一开始就打上标记，否则在搜索过程中，如果一开始就是0，那么可能会出现
				//同一行存在2个1，或者多个1的情况，导致出错！
			}
			if (mat[row][col] == 0) {
				dfsrow[row].zerocnt = dfsrow[row].zerocnt + 1;
			}
		}
	}
	sort(dfsrow + 1, dfsrow + 10, cmp);
}


int calsum(int row, int col) {
	//参考大佬的代码，发现从外面往里面剥代码会很简单
	if (row == 1 || row == 9 || col == 1 || col == 9)return mat[row][col] * 6;
	if (row == 2 || row == 8 || col == 2 || col == 8)return mat[row][col] * 7;
	if (row == 3 || row == 7 || col == 3 || col == 7)return mat[row][col] * 8;
	if (row == 4 || row == 6 || col == 4 || col == 6)return mat[row][col] * 9;
	else return mat[row][col]*10;
}

void dfs(int pcnt,int cursum) {
	//pcnt表示正在统计第pcnt个点
	if (pcnt == 82) {
		maxres = max(maxres, cursum);
		flag = 1;
		return;
	}

	Point curpoint = points[pcnt];//当前要统计的点
	int row = curpoint.row;
	int col = curpoint.col;
	int blkind = loc2blkind(row, col);

	if (mat[row][col] != 0) {//如果当前的统计点不为0，则打上标记，求和之后继续深搜
		int addval = calsum(row, col);
		dfs(pcnt + 1, cursum + addval);
	}
	else if (mat[row][col] == 0) {//如果当前的统计点为0，那么就需要枚举
		for (int i = 1; i <= 9; i++) {//枚举数字
			if (rowmark[row][i] != 1 && colmark[col][i] != 1 && blockmark[blkind][i] != 1) {

				rowmark[row][i] = 1;
				colmark[col][i] = 1;
				blockmark[blkind][i] = 1;
				mat[row][col] = i;//标记

				int addval = calsum(row, col);
				dfs(pcnt + 1, cursum + addval);//这里尽量用加法

				rowmark[row][i] = 0;
				colmark[col][i] = 0;
				blockmark[blkind][i] = 0;
				mat[row][col] = 0;//擦除标记，回溯
			}
		}
	}
}


int main() {
	getdata();
	//计算点的顺序
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