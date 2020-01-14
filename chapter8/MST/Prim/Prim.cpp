#include<iostream>
#define MaxSize 1001
#define Inf 65535
#define Error -1
using namespace std;
typedef struct GraphNode* Graph;
typedef int Vertex;
struct GraphNode {
	int Nv;
	int Ne;
	int Weight[MaxSize][MaxSize];
};
void InsertEdge(Graph G,int M) {
	/*向G中插入M条边*/
	Vertex v1, v2;
	int weight;
	auto W = G->Weight;
	for (int i = 0; i < M; i++) {
		cin >> v1 >> v2 >> weight;
		W[v1][v2] = weight;//序号从1-N
		W[v2][v1] = weight;
		G->Ne++;
	}
}
int dist[MaxSize];
int collect[MaxSize];//这里其实不需要collect，因为dist[i]==0就说明已经收录进集合了
int path[MaxSize];

Vertex FindMinDist(int Dist[], int Collect[],int Nv) {
	/*搜寻未收录顶点中的最小边，由于是未收录的顶点，因此不可能形成回路，但是dist[]的定义和dijkstra不同，要注意这点！*/
	int MinDist = Inf;
	Vertex V;
	for (int i = 1; i <= Nv; i++) {
		if (Collect[i] != 1 && dist[i]<MinDist) {
			V = i;
			MinDist = dist[i];
		}
	}
	if (MinDist < Inf)return V;
	else
		return Error;

}

int Prim(Graph G) {
	Vertex S = 1;//这里我打算做个特殊处理，假设从S点开始建立最小生成树，S可以改变，而不是固定从0开始
	/*初始化dist[]与collect[],path[]*/
	for (int i = 1; i <= G->Nv; i++) {
		dist[i] = Inf;
		collect[i] = -1;
		path[i] = -1;
	}
	path[S] = -1;
	dist[S] = 0;
	collect[S] = 1;//将S点收入
	
	/*对S邻接点进行初始化*/
	for (int i = 1; i <= G->Nv; i++) {
		if (G->Weight[S][i] != Inf) {
			dist[i] = G->Weight[S][i];
			path[i] = S;
		}
	}
	int TotalCount = 0;
	Vertex V;
	int Vcount = 1;//prim算法收录的点个数是NV个，收录边的条数是NV-1条
	/*执行prim算法*/
	while (1) {
		V = FindMinDist(dist,collect,G->Nv);//寻找未收录点中的最小边
		if (V == Error)break;
		collect[V] = 1;//将V收入集合,从此不再计算
		Vcount++;//收入的节点数加1
		TotalCount = TotalCount + dist[V];//添加边长
		/*更新V周围的点*/
		for (int i = 1; i <= G->Nv; i++) {
			if (G->Weight[V][i] != Inf&&collect[i] != 1) {
				/*未收录的邻接点中如果因为收录了dist[]使得边长更小了，那么就更新dist和path*/
				if (G->Weight[V][i] < dist[i]) {
					dist[i] = G->Weight[V][i];
					path[i] = V;
				}
			}
		}
	}
	if (Vcount != G->Nv)
		TotalCount = -1;
	return TotalCount;
}

int main() {
	int N, M;
	cin >> N >> M;
	Vertex v1, v2;
	int weight;
	Graph G = new GraphNode;
	G->Nv = N;
	G->Ne = 0;
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			G->Weight[i][j] = Inf;
		}
	}
	InsertEdge(G,M);
	/*以上为简略的使用邻接矩阵建图*/
	cout<<Prim(G);


	return 0;
}