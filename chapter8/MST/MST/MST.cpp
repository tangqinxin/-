#include <iostream>
#define MaxSize 1001
using namespace std;
typedef int Vertex;
typedef int ElementType;
/*ͼ���ڽӱ���*/
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
/*��С�ѵĶ���*/
typedef Vertex SetType[MaxSize];//���ڼ�¼ÿ���������ļ���
typedef Vertex SetName;
void PercDown(Edge Eset, int i, int N);
void InitializeEset(Graph G, Edge Eset) {
	/*��ͼ����ʼ��������*/
	List tmp;
	int Ecount = 1;//������Ҳ��1��ʼ������������С������
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

	/*����Ϊ��С��*/
	for (int i = Ecount / 2; i > 0; i--) {
		PercDown(Eset, i, Ecount);
	}

}
void PercDown(Edge Eset, int i, int N) {
	/*��Eset�����飬�ӵ�i����������������ѣ�����Ĵ�СΪN����������Ϊ[1,N]*/
	ENode Etmp = Eset[i];
	int child, parent;
	for (parent = i; parent * 2 <= N; parent = child) {
		child = 2 * parent;
		if (child != N&&Eset[child].Weight > Eset[child + 1].Weight) { //�Ҹ�С��
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
	/*��Eset�е���һ����̱�*/
	ENode E = Eset[1];
	Eset[1] = Eset[N];
	PercDown(Eset, 1, N - 1);
	cout << E.v1 << endl;
	return E;
}

Vertex FindRoot(SetType S, Vertex V) {
	/*����V���ڵĸ��ڵ�ļ��ϣ�ʹ��·��ѹ��*/
	if (S[V] < 0)
		return V;
	else
		return S[V] = FindRoot(S, S[V]);
}

int IsCycle(SetType V_Set, ENode E) {
	/*�����¼��E�Ƿ����V_Set�й��ɻ�·,�ǻ�·����1�����ǻ�·����0*/
	Vertex v1 = E.v1;
	Vertex v2 = E.v2;
	Vertex root1, root2;
	root1 = FindRoot(V_Set, v1);
	root2 = FindRoot(V_Set, v2);
	if (root1 == root2) {
		return 1;//v1,v2��ͬһ�������棬����ͨ�ṹ�ɻ�·
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
	SetType VSet;//VSet��һ����С����������
	for (int i = 1; i <= G->Nv; i++) {/*��ʼ�����㼯��VSet*/
		VSet[i] = -1;
	}
	TotalWeight = 0;
	EIsCount = 0;/*���ڼ�¼��¼�ı�*/
	CountPopEdge = 0;/*���ڼ�¼�����ıߣ������ı߲�һ�����ᱻ��¼*/
	ENode Etmp;
	while (EIsCount < G->Nv - 1) {
		if (CountPopEdge >= G->Ne)break;
		Etmp = PopEdge(G, Eset, G->Ne - CountPopEdge);
		CountPopEdge++;
		if (IsCycle(VSet, Etmp) == 0) {
			Union(VSet, Etmp.v1, Etmp.v2);//����ͬһ�������棬����v1,v2
			TotalWeight = TotalWeight + Etmp.Weight;
			EIsCount++;
		}
	}
	if (EIsCount < G->Nv - 1) {//û���ܹ�������С���������߲���������ͨ
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
	Edge Eset;/*����һ��ȫ�ֱ���Eset��Ϊ�߼��ϣ���һ����С��*/
	Eset = new ENode[M + 1];
	InitializeEset(G, Eset);
	cout << Kruskal(G,Eset);
	return 0;
}
