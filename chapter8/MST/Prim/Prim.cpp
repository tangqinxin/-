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
	/*��G�в���M����*/
	Vertex v1, v2;
	int weight;
	auto W = G->Weight;
	for (int i = 0; i < M; i++) {
		cin >> v1 >> v2 >> weight;
		W[v1][v2] = weight;//��Ŵ�1-N
		W[v2][v1] = weight;
		G->Ne++;
	}
}
int dist[MaxSize];
int collect[MaxSize];//������ʵ����Ҫcollect����Ϊdist[i]==0��˵���Ѿ���¼��������
int path[MaxSize];

Vertex FindMinDist(int Dist[], int Collect[],int Nv) {
	/*��Ѱδ��¼�����е���С�ߣ�������δ��¼�Ķ��㣬��˲������γɻ�·������dist[]�Ķ����dijkstra��ͬ��Ҫע����㣡*/
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
	Vertex S = 1;//�����Ҵ����������⴦�������S�㿪ʼ������С��������S���Ըı䣬�����ǹ̶���0��ʼ
	/*��ʼ��dist[]��collect[],path[]*/
	for (int i = 1; i <= G->Nv; i++) {
		dist[i] = Inf;
		collect[i] = -1;
		path[i] = -1;
	}
	path[S] = -1;
	dist[S] = 0;
	collect[S] = 1;//��S������
	
	/*��S�ڽӵ���г�ʼ��*/
	for (int i = 1; i <= G->Nv; i++) {
		if (G->Weight[S][i] != Inf) {
			dist[i] = G->Weight[S][i];
			path[i] = S;
		}
	}
	int TotalCount = 0;
	Vertex V;
	int Vcount = 1;//prim�㷨��¼�ĵ������NV������¼�ߵ�������NV-1��
	/*ִ��prim�㷨*/
	while (1) {
		V = FindMinDist(dist,collect,G->Nv);//Ѱ��δ��¼���е���С��
		if (V == Error)break;
		collect[V] = 1;//��V���뼯��,�Ӵ˲��ټ���
		Vcount++;//����Ľڵ�����1
		TotalCount = TotalCount + dist[V];//��ӱ߳�
		/*����V��Χ�ĵ�*/
		for (int i = 1; i <= G->Nv; i++) {
			if (G->Weight[V][i] != Inf&&collect[i] != 1) {
				/*δ��¼���ڽӵ��������Ϊ��¼��dist[]ʹ�ñ߳���С�ˣ���ô�͸���dist��path*/
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
	/*����Ϊ���Ե�ʹ���ڽӾ���ͼ*/
	cout<<Prim(G);


	return 0;
}