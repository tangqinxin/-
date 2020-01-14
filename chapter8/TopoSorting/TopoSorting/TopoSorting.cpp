#include<iostream>
#include<queue>
using namespace std;
#define Maxsize 100
/*拓扑排序，考虑使用邻接表建图*/
typedef struct GraphNode* Graph;
typedef int Vertex;
typedef int Weight;
typedef struct LNode* PtrToLNode;
struct LNode {
	Vertex V;
	Weight weight;
	PtrToLNode Next;
	LNode(){}
	LNode(int V2,int w):V(V2),weight(w),Next(NULL){}
};
typedef struct VNode {
	PtrToLNode FirstEdge;
	VNode():FirstEdge(NULL){}
}PtrToLNodeArr[Maxsize];
struct GraphNode {
	int Nv;
	int Ne;
	PtrToLNodeArr Points;
};
Graph BuildGraph(int N, int M) {
	/*建立一个有N个顶点，M条边的有向图*/
	Graph G = new GraphNode;
	G->Nv = N;
	G->Ne = M;
	Vertex v1, v2;
	Weight w;
	PtrToLNode L;
	for(int i=0;i<M;i++){
		cin >> v1 >> v2 >> w;
		L = new LNode(v2,w);
		L->Next = G->Points[v1].FirstEdge;
		G->Points[v1].FirstEdge = L;//有向图只记录v1->v2的
	}
	return G;
}

/*拓扑排序关键路径问题*/
void IndegreeCount(Graph G, int InDegree[]) {
	/*统计G图中的入度，结果写在InDegree[]中*/
	int i, Index;
	PtrToLNode tmp;
	for (int i = 0; i < G->Nv; i++) {//对Nv个点统计入度
		tmp = G->Points[i].FirstEdge;
		while (tmp != NULL) {
			InDegree[tmp->V]++;//第i个点的所有邻接节点V的入度+1
			tmp = tmp->Next;
		}
	}
}
/*
template<class T>
int GetArrSize(const T& Obj) {
	return sizeof(Obj) / sizeof(Obj[0]);
}

void FindInDegIsZero(int InDegree[], queue<Vertex>& q) {
	/*查找InDegree中入度为0的点，并加入队列
	int ArrSize=GetArrSize(InDegree);
	for (int i = 0; i < ArrSize; i++) {
		if (InDegree[i] == 0) {
			q.push(i);
		}
	}
}
*/
/*拓扑排序主函数*/
int TopSorting(Graph G) {
	int InDegree[Maxsize];//统计入度
	int Time[Maxsize];//统计到每个节点最早什么时候完成
	queue<Vertex> q;
	Vertex V;
	for (int i = 0; i < G->Nv; i++) {
		Time[i] = 0;//初始化Time和InDegree的每个节点
		InDegree[i] = 0;
	}
	IndegreeCount(G, InDegree);//统计入度
	
	for (int i = 0; i < G->Nv; i++) {//查找InDegree中入度为0的点，并加入队列
		if (InDegree[i] == 0) {
			q.push(i);
		}
	}

	PtrToLNode tmp;
	Vertex W;
	int Vcout = 0;//统计弹出了多少个节点，判断拓扑排序是否失效,正常应该为G->Nv个点
	while (q.empty() != 1) {
		V = q.front();
		q.pop();//弹出当前节点V
		Vcout++;
		for (tmp = G->Points[V].FirstEdge; tmp != NULL; tmp = tmp->Next) {
			/*对V的下节点W点进行更新*/
			W = tmp->V;
			InDegree[W]--;
			if (InDegree[W] == 0) {
				q.push(W);
			}
			if (Time[V] + tmp->weight > Time[W]) {//如果节点W的时间比V+<v,w>更小，那么选取更大的那个
				Time[W] = Time[V] + tmp->weight;
			}
		}
	}

	int MaxTime = 0;
	for (int i = 0; i < G->Nv; i++) {
		MaxTime = Time[i] > MaxTime ? Time[i] : MaxTime;//选出Time[i]中最大的值
	}

	if (Vcout == G->Nv)return MaxTime;
	else return -1;
}


int main() {
	int N, M;
	cin >> N >> M;
	Graph G;
	G = BuildGraph(N, M);
	int res = TopSorting(G);
	if (res == -1)cout << "Impossible";
	else cout << res;
	return 0;
}