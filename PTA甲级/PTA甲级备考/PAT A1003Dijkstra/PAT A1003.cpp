#include<iostream>
#include<cstring>
#include<climits>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
#define maxsize 505
int G[maxsize][maxsize];//边权
int dist[maxsize];//最短路径记录，从c1出发到各点的单源最短路径
bool visit[maxsize] = { false };
int CityWeight[maxsize];//点权数据和
int CityWeightSum[maxsize];//点权和从c1到c2
int Count[maxsize];//最短路径数
int  N, M, c1, c2;

int FindMinDist(int Dist[]) {
	int mindist = INT_MAX;
	int minindex = -1;
	for (int i = 0; i < N; i++) {
		if (visit[i]==false&&dist[i] < mindist) {
			mindist = dist[i];
			minindex = i;
		}
	}
	return minindex;
}


void Dijkstra(int s) {
	//单源最短路径，要求更新到各点的最短路径数，和最短边权，以及最大点权和

	//初始化Count[]，最短路径数Count[]，点权CityWeight[]
	memset(Count, 0, sizeof(Count));
	Count[c1] = 1;//到起点的最短路径初始化为1
	//初始化CityWeightSum[]，点权和
	fill(CityWeightSum, CityWeightSum + maxsize, 0);//初始化为0
	CityWeightSum[c1] = CityWeight[c1];//起点初始化为起始值
	//初始化最短路径数组
	fill(dist, dist + maxsize, INT_MAX);
	dist[c1] = 0;

	for (int i = 0; i < N; i++) {//循环N次
		//寻找最小路径
		int u = FindMinDist(dist);//找到路径起点

		if (u == -1) {
			break;//已经找不到了，那么就跳出
		}
		
		//如果是合法的u那么将其记录为访问过
		visit[u] = true;
		for (int v = 0; v < N; v++) {//枚举中介点u的邻边,进行更新
			if (visit[v]==false&&G[u][v] != INT_MAX) {
				if (G[u][v]+dist[u]<dist[v]) {
					dist[v] = dist[u] + G[u][v];
					Count[v] = Count[u];
					CityWeightSum[v] = CityWeightSum[u] + CityWeight[v];
				}
				else if (dist[u]+G[u][v]==dist[v]) {
					Count[v] += Count[u];
					CityWeightSum[v] = max(CityWeightSum[v], CityWeightSum[u] + CityWeight[v]);//比较选择更大的那一个
				}
			}
		}
	}
	
}

int main() {
	scanf("%d %d %d %d", &N, &M, &c1, &c2);
	for (int i = 0; i < N; i++) {
		scanf("%d",&CityWeight[i]);
	}

	fill(G[0], G[0] + maxsize*maxsize, INT_MAX);//二维图初始化
	for (int i = 0; i < M; i++) {
		int u, v,edge;
		scanf("%d %d %d", &u, &v, &edge);
		G[u][v] = edge;
		G[v][u] = edge;
	}
	Dijkstra(c1);
	printf("%d %d", Count[c2], CityWeightSum[c2]);

	return 0;
}