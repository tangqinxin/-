#include<iostream>
using namespace std;
#define MaxN 500
#define Inf 1000
#define Error -1
int dist[MaxN];
int cost[MaxN];
int collect[MaxN];
int path[MaxN];
typedef int Vertex;
typedef struct GraphNode* Graph;
struct GDataNode {
	int dist;
	int cost;
};
struct GraphNode{
	int Nv;
	GDataNode G[MaxN][MaxN];
};



void BuildGraph(Graph Gmap, int N_edge) {
	auto Gdata = Gmap->G;
	int S, D;
	int Dist, Cost;
	int Nv = Gmap->Nv;
	for (int i = 0; i < Nv; i++) {
		for (int j = 0; j < Nv; j++) {
			Gdata[i][j].cost = Inf;
			Gdata[i][j].dist = Inf;
		}
	}
	for (int i = 0; i < N_edge; i++) {
		cin >> S >> D >> Dist >> Cost;
		Gdata[S][D].dist = Dist;
		Gdata[S][D].cost = Cost;
		Gdata[D][S].dist = Dist;
		Gdata[D][S].cost = Cost;
	}
}


Vertex FindMinDist(int Dist[], int Collect[], int N) {
	Vertex V;
	int MinDist = Inf;
	for (int i = 0; i < N; i++) {
		if (Collect[i] != 1 && Dist[i] < MinDist) {
			MinDist = Dist[i];
			V = i;
		}
	}
	if (MinDist < Inf)
		return V;
	else
		return Error;
}

void Dijkstra(Graph G, Vertex S, Vertex D) {
	/*求G图中，S到D的最短路径长度，并输出相对应的花销，花销相同输出最小的*/
	for (int i = 0; i < G->Nv; i++) {
		dist[i] = Inf;
		path[i] = -1;
		cost[i] = Inf;
		collect[i] = 0;
	}

	dist[S] = 0;
	collect[S] = 1;
	cost[S] = 0;
	auto Gdata = G->G;
	for (int i = 0; i < G->Nv; i++) {
		if (Gdata[S][i].dist != Inf) {
			dist[i] = Gdata[S][i].dist;
			cost[i] = Gdata[S][i].cost;
			path[i] = S;
		}
	}

	Vertex V;
	while (1) {
		V = FindMinDist(dist, collect,G->Nv);
		if (V == Error)break;
		collect[V] = 1;
		for (int W=0; W < G->Nv; W++) {
			if ( Gdata[V][W].dist != Inf) {/*对V的邻接且未收录的点进行比较*/
				if (collect[W] != 1 && dist[W] > dist[V] + Gdata[V][W].dist) {
					dist[W] = dist[V] + Gdata[V][W].dist;
					cost[W] = cost[V] + Gdata[V][W].cost;
					path[W] = V;
				}
				if(dist[W] == dist[V] + Gdata[V][W].dist&&cost[W]>cost[V]+ Gdata[V][W].cost) {
					cost[W] = cost[V] + Gdata[V][W].cost;
					path[W] = V;
				}
			}
		}
	}
	cout << dist[D] << " " << cost[D];
}


int main() {
	int N, M, S, D;
	cin >> N >> M>>S>>D;
	Graph G = new GraphNode;
	G->Nv = N;
	BuildGraph(G, M);
	Dijkstra(G, S, D);

	return 0;
}