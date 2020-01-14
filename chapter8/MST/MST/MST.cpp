#include <iostream>
#define MaxSize 1001
using namespace std;
typedef int Vertex;
typedef int ElementType;
/*图的邻接表定义*/
typedef struct ListNode* List;
typedef struct ENode* Edge;
struct ENode {
	Vertex v1;
	Vertex v2;
	ElementType Weight;
	ENode(const ENode& _E):v1(_E.v1),v2(_E.v2),Weight(_E.Weight){}
	ENode():v1(0),v2(0),Weight(0){}
};
struct ListNode {
	Vertex V;
	ElementType Weight;
	List Next;
	ListNode() :Next(NULL) {}
};

typedef List PtrToNode;
typedef struct VNode {
	PtrToNode FirstEdge;
}PtrArray[MaxSize];

typedef struct GraphNode* Graph;
struct GraphNode {
	int Nv;
	int Ne;
	PtrArray heads;
};


Graph CreatGraph(int N) {
	Graph G = new GraphNode;
	G->Nv = N;
	G->Ne = 0;
	for (int i = 0; i <= N; i++) {
		G->heads[i].FirstEdge = NULL;
	}
	return G;
}

void InsertEdge(Graph G) {
	Vertex v1, v2;
	ElementType Weight;
	cin >> v1 >> v2 >> Weight;
	List tmp = new ListNode;
	tmp->Next = G->heads[v1].FirstEdge;
	tmp->V = v2;
	tmp->Weight = Weight;
	G->heads[v1].FirstEdge = tmp;

	tmp = new ListNode;
	tmp->Next = G->heads[v2].FirstEdge;
	tmp->V = v1;
	tmp->Weight = Weight;
	G->heads[v2].FirstEdge = tmp;
	G->Ne++;

}
/*最小堆的定义*/
typedef Vertex SetType[MaxSize];//用于记录每个点所属的集合
typedef Vertex SetName;
void PercDown(Edge Eset, int i, int N);
void InitializeEset(Graph G, Edge Eset) {
	/*用图来初始化边数组*/
	List tmp;
	int Ecount = 1;//边数组也从1开始计数，方便最小堆排列
	for (int i = 1; i <= G->Nv; i++) {
		tmp = G->heads[i].FirstEdge;
		while (tmp != NULL) {
			if (tmp->V < i) {
				Eset[Ecount].v1 = i;
				Eset[Ecount].v2 = tmp->V;
				Eset[Ecount].Weight = tmp->Weight;
				Ecount++;
			}
			tmp = tmp->Next;
		}
	}

	/*调整为最小堆*/
	for (int i = Ecount / 2; i > 0; i--) {
		PercDown(Eset, i, Ecount);
	}

}
void PercDown(Edge Eset, int i, int N) {
	/*对Eset边数组，从第i个顶点进行向下整堆，数组的大小为N，数组区间为[1,N]*/
	ENode Etmp = Eset[i];
	int child, parent;
	for (parent = i; parent * 2 <= N; parent = child) {
		child = 2 * parent;
		if (child != N&&Eset[child].Weight > Eset[child + 1].Weight) { //找更小的
			child++;
		}
		if (Eset[child].Weight < Etmp.Weight) {
			Eset[parent] = Eset[child];
		}
		else break;
	}
	Eset[parent] = Etmp;
}

ENode PopEdge(Graph G, Edge Eset, int N) {
	/*从Eset中弹出一条最短边*/
	ENode E = Eset[1];
	Eset[1] = Eset[N];
	PercDown(Eset, 1, N - 1);
	cout << E.v1 << endl;
	return E;
}

Vertex FindRoot(SetType S, Vertex V) {
	/*返回V所在的根节点的集合，使用路径压缩*/
	if (S[V] < 0)
		return V;
	else
		return S[V] = FindRoot(S, S[V]);
}

int IsCycle(SetType V_Set, ENode E) {
	/*检查收录边E是否会在V_Set中构成回路,是回路返回1，不是回路返回0*/
	Vertex v1 = E.v1;
	Vertex v2 = E.v2;
	Vertex root1, root2;
	root1 = FindRoot(V_Set, v1);
	root2 = FindRoot(V_Set, v2);
	if (root1 == root2) {
		return 1;//v1,v2在同一棵树里面，再联通会构成回路
	}
	else {
		return 0;
	}
}

void Union(SetType V_Set, Vertex v1, Vertex v2) {
	//V_Set[FindRoot(V_Set, v1)] = FindRoot(V_Set, v2);
	V_Set[v1] = v2;
}

int Kruskal(Graph G,Edge Eset) {
	int TotalWeight;
	int EIsCount, CountPopEdge;
	SetType VSet;//VSet是一个最小生成树集合
	for (int i = 1; i <= G->Nv; i++) {/*初始化顶点集合VSet*/
		VSet[i] = -1;
	}
	TotalWeight = 0;
	EIsCount = 0;/*用于记录收录的边*/
	CountPopEdge = 0;/*用于记录弹出的边，弹出的边不一定都会被收录*/
	ENode Etmp;
	while (EIsCount < G->Nv - 1) {
		if (CountPopEdge >= G->Ne)break;
		Etmp = PopEdge(G, Eset, G->Ne - CountPopEdge);
		CountPopEdge++;
		if (IsCycle(VSet, Etmp) == 0) {
			Union(VSet, Etmp.v1, Etmp.v2);//不在同一棵树里面，连接v1,v2
			TotalWeight = TotalWeight + Etmp.Weight;
			EIsCount++;
		}
	}
	if (EIsCount < G->Nv - 1) {//没有能够生成最小生成树，边不够，不连通
		TotalWeight = -1;
	}
	return TotalWeight;
}



int main() {
	int N, M;
	cin >> N >> M;
	Graph G = CreatGraph(N);
	for (int i = 0; i < M; i++) {
		InsertEdge(G);
	}
	Edge Eset;/*定义一个全局变量Eset作为边集合，是一个最小堆*/
	Eset = new ENode[M + 1];
	InitializeEset(G, Eset);
	cout << Kruskal(G,Eset);
	return 0;
}
