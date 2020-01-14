#include<iostream>
#include <queue>
using namespace std;
typedef int Vertex;
typedef Vertex ElementType;
typedef struct ListNode* List;
typedef List PtrToLNode;
#define MaxSize 1000
int Visit[MaxSize];
struct ListNode {
	ElementType v;
	PtrToLNode Next;
	ListNode() :Next(NULL) {}
	ListNode(int _v) :v(_v),Next(NULL) {}
};
typedef struct GraphNode* Graph;
struct GraphNode {
	int Nv;
	List heads;
};

Graph BuildGraph(int N) {
	Graph G = new GraphNode;
	G->Nv = N;
	G->heads = new ListNode[N+1];
	for (int i = 0; i < N + 1; i++) {
		G->heads[i].v = i;
	}
	return G;
}

void ResetVisit(int Visit[],int N) {
	for (int i = 0; i < N+1; i++) {
		Visit[i] = 0;
	}
}

void InsertEdge(Graph G, int v1, int v2) {
	List tmp = new ListNode(v2);
	tmp->Next = G->heads[v1].Next;
	G->heads[v1].Next = tmp;
	tmp = new ListNode(v1);
	tmp->Next = G->heads[v2].Next;
	G->heads[v2].Next = tmp;
}

int BFS(Graph G, int ve) {
	/*获取第Ve点的对应的六度空间数量*/
	queue<List> q;
	List Ptr_V;
	int count;
	if (Visit[ve] != 1) {
		Visit[ve] = 1;
		q.push(G->heads+ve);
		count = 1;
	}
	int RoundLast=q.size();
	int RoundCur;
	int layer = 0;//表示已经统计完了第layer层
	while (!q.empty()) {
		Ptr_V = q.front();
		q.pop();
		RoundLast--;
		for (Ptr_V=G->heads[Ptr_V->v].Next; Ptr_V != NULL; Ptr_V = Ptr_V->Next) {
			if (Visit[Ptr_V->v] != 1) {
				Visit[Ptr_V->v] = 1;
				q.push(Ptr_V);
				count++;
			}
		}
		RoundCur = q.size();
		if (RoundLast == 0) {
			RoundLast = RoundCur;
			layer++;
		}
		if (layer == 6)break;
	}
	return count;
}

void SDS(Graph G) {
	int Nv = G->Nv;
	int count = 0;
	double percent;
	for (int i = 1; i < Nv+1; i++) {
		count = BFS(G, i);
		printf("%d: %.2f%%\n",i,(double)(100*count)/(double) Nv);
		ResetVisit(Visit, Nv);
	}
}

int DFS(Graph G, int ve, int layer) {
	List Ptr_V;
	int count=0;
	if (Visit[ve] != 1) {
		Visit[ve] = 1;
		count++;
	}
	if (layer == 0)return count;
	else {
		for (Ptr_V = G->heads[ve].Next; Ptr_V != NULL; Ptr_V = Ptr_V->Next) {
			if (Visit[Ptr_V->v] != 1) {
				count=count+DFS(G, Ptr_V->v, layer - 1);
			}
		}
	}
	return count;
}


void SDS_DFS(Graph G) {
	int Nv = G->Nv;
	int count = 0;
	double percent;
	for (int i = 1; i < Nv + 1; i++) {
		count = DFS(G, i,6);
		printf("%d: %.2f%%\n", i, (double)(100 * count) / (double)Nv);
		ResetVisit(Visit, Nv);
	}
}

int main() {
	int N, M;
	cin >> N >> M;
	Graph G = BuildGraph(N);
	int v1, v2;
	for (int i = 0; i < M; i++) {
		cin >> v1 >> v2;
		InsertEdge(G, v1, v2);
	}
	SDS(G);
	//SDS_DFS(G);
	return 0;
}