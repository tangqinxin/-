#include<iostream>
#include<math.h>
#define Maxsize 100
#define Rcenter 15
using namespace std;
struct Point {
	int x;
	int y;
	int vst;
}Points[Maxsize];
typedef Point* PtrToPoint;
typedef PtrToPoint PointArr;

void GetData(PointArr P_Arr,int N){
	for (int i = 0; i < N; i++) {
		cin >> P_Arr[i].x >> P_Arr[i].y;
		P_Arr[i].vst = 0;
	}
}
int IsSave(const Point& P1, int D) {
	int x = P1.x;
	int y = P1.y;
	int res = (x + D >= 50 || x - D <= -50 || y + D >= 50 || y - D <= -50);
	return res;
}



int FirstJump(Point& P,int r_center, int D) {
	int x = P.x;
	int y = P.y;
	double dist = sqrt(x*x + y*y);
	return dist <= (r_center + D) ? 1 : 0;
}

int Jump(Point& P1, Point& P2, int D) {
	int dx = P1.x- P2.x;
	int dy = P1.y- P2.y;
	double res = sqrt(dx*dx + dy*dy);
	return res <= D ? 1 : 0;
}

int DFS(PointArr P_Arr,Point& P, int N, int D) {
	/*在P_Arr的所有点中，从P点开始跳，P_Arr的size为N，跳跃距离为D*/
	int res = 0;
	if (P.vst == 0) {
		P.vst = 1;
		if (IsSave(P, D) == 1) {
			res = 1;
			return res;//如果当前节点就是安全的，那么就直接返回安全
		}
	}

	for (int i = 0; i < N; i++) {
		if(P_Arr[i].vst!=1&&Jump(P,P_Arr[i],D)==1){
			res=DFS(P_Arr, P_Arr[i], N, D);
			if (res == 1)break;
		}
	}
	return res;
}

void Save007(PointArr P_Arr,int N,int D) {
	int res = 0;
	for (int i = 0; i < N; i++) {
		if (P_Arr[i].vst != 1 && FirstJump(P_Arr[i], Rcenter, D)) {/*从中心开始遍历所有点，如果这个点没有被访问过，而且第一跳可以跳上去，就对这个点做DFS*/
			res = DFS(P_Arr,P_Arr[i], N, D);
			if (res == 1)break;
		}
	}
	if (res == 1)cout << "Yes";
	if (res == 0)cout << "No";

}

int main() {
	int N, D;
	cin >> N >> D;
	GetData(Points, N);
	Save007(Points, N, D);
	return 0;
}