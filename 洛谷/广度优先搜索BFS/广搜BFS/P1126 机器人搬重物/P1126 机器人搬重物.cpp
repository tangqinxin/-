#include<iostream>
#include<map>
#include<queue>
#include<climits>
#include<algorithm>
#define maxsize 55
using namespace std;
int inimat[maxsize][maxsize];
int mat[maxsize][maxsize];
int timemark[maxsize][maxsize];
int dir[][4] = { {0,1},{1,0},{0,-1},{-1,0} };
map<char, int> dir_vec = { {'E',0},{'S',1},{'W',2},{'N',3} };
char dir_hash[4] = { 'E','S','W','N' };
int N, M;//原始输入
int n, m;//点图对应的维度

void GridToPointMap() {
	//将格子图转换为点图
	//先生成，生成对应数量的点
	n = N + 1;
	m = M + 1;
	//染色，根据格子图将对应颜色的点进行染色
	for (int row = 1; row <= n; row++) {
		for (int col = 1; col <= m; col++) {
			if (inimat[row][col] == 1) {
				mat[row][col] = 1;
				mat[row + 1][col + 1] = 1;
				mat[row][col + 1] = 1;
				mat[row + 1][col] = 1;
			}
		}
	}
}



struct node {
	//状态结点定义
	int row;
	int col;
	char dir;
	int time;
};

void TurnRight(node& obj) {
	obj.time++;
	char inidir = obj.dir;
	if (dir_vec[inidir] < 3) {
		obj.dir = dir_hash[dir_vec[inidir]+1];
	}
	else {
		obj.dir = dir_hash[0];
	}
}

void TurnLeft(node& obj) {
	obj.time++;
	char inidir = obj.dir;
	if (dir_vec[inidir] > 0) {
		obj.dir = dir_hash[dir_vec[inidir]-1];
	}
	else {
		obj.dir = dir_hash[3];
	}
}

void TurnBack(node& obj) {
	obj.time=obj.time+2;
	char inidir = obj.dir;
	switch (inidir) {
	case 'E':
		obj.dir = 'W';
		break;
	case'W':
		obj.dir = 'E';
		break;
	case'N':
		obj.dir = 'S';
		break;
	case'S':
		obj.dir = 'N';
		break;
	default:
		break;
	}
}

void turndir(node& obj, int dir_index) {
	//对obj对象进行方向调整，其中dir_index作为循环接口调用函数
	switch (dir_index) {
	case 0:
		break;
	case 1:
		TurnRight(obj);
		break;
	case 2:
		TurnLeft(obj);
		break;
	case 3:
		TurnBack(obj);
		break;
	default:
		break;
	}
}

bool pace(node obj, int step) {
	//obj向当前方向行走step，在该过程中没有障碍
	bool res = true;

	int currow = obj.row;
	int curcol = obj.col;
	int rowinc = dir[dir_vec[obj.dir]][0];
	int colinc = dir[dir_vec[obj.dir]][1];
	for (int i = 1; i <= step; i++) {
		int nextrow = currow + rowinc*i;
		int nextcol = curcol + colinc*i;
		if (nextrow>n-1||nextrow<2||nextcol>m-1||nextcol<2||mat[nextrow][nextcol] == 1) {
			res = false;//越界+障碍判断，路径上只要有一步有阻碍，就跳出循环
			break;
		}
	}
	return res;
}

node GoPoint(node obj, int step) {
	node res = obj;
	res.time++;
	res.row = res.row + dir[dir_vec[res.dir]][0] * step;
	res.col = res.col + dir[dir_vec[res.dir]][1] * step;
	return res;
}

int bfs(int srow, int scol, int trow, int tcol, char begindir) {
	if (srow == trow&&scol == tcol)return 0;

	node start;
	start.row = srow;
	start.col = scol;
	start.dir = begindir;
	start.time = 0;
	queue<node> q;
	q.push(start);

	while (!q.empty()) {
		node tmp = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			node tmp2 = tmp;
			turndir(tmp2, i);//转向不同方向,转完方向后时间已经计算完转向时间
			for (int step = 1; step <= 3; step++) {
				if (pace(tmp2, step)) {//如果该路径可以走
					node tmp3=GoPoint(tmp2, step);
					if (tmp3.time < timemark[tmp3.row][tmp3.col]) {//如果这一步可以更新时间
						timemark[tmp3.row][tmp3.col] = tmp3.time;//更新时间
						q.push(tmp3);//入队
					}
				}
			}
		}
	}
	
	if (timemark[trow][tcol] == INT_MAX) {
		return -1;
	}
	else {
		return timemark[trow][tcol];
	}
}


int main() {
	fill(timemark[0], timemark[0] + maxsize*maxsize, INT_MAX);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> inimat[i][j];//原始地图输入
		}
	}

	int s_row, s_col, t_row, t_col;
	char begin_dir;
	cin >> s_row >> s_col >> t_row >> t_col >> begin_dir;
	GridToPointMap();//格子图转换为点图
	cout<<bfs(s_row+1, s_col+1, t_row+1, t_col+1, begin_dir);


	return 0;
}