#include<iostream>
#include<cmath>
#include<algorithm>
#include<climits>
using namespace std;
#define maxsize 20
int used[maxsize];//记录访问过的点数
double minres = INT_MAX;
int n;

struct Point {
	double x;
	double y;
};
Point points[maxsize];


double dist2p(Point a, Point b) {
	//计算两点之间距离
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

void dfs(int num,int curpos,double sum) {
	//num表示已经访问过的点的数量
	if (num<n&&sum>=minres) {
		return;//剪枝
	}
	if (num >= n) {
		minres = min(sum, minres);
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (used[i] != 1) {
			used[i] = 1;
			double dst = dist2p(points[curpos], points[i]);
			dfs(num + 1, i, sum + dst);
			used[i] = 0;
		}
	}
}



int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> points[i].x >> points[i].y;
	}
	points[0].x = 0;
	points[0].y = 0;
	dfs(0,0,0);
	printf("%.2f", minres);
	return 0;
}