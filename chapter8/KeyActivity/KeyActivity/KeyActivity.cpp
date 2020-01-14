#include<iostream>
#include<queue>
#include<stack>
#include<map>
#include<utility>
using namespace std;
#define Maxsize 101
#define Inf 65535
typedef int Vertex;
typedef int WeightType;
typedef struct LNode* PtrToLNode;
typedef struct VNode {
	PtrToLNode FirstEdge;
	WeightType Earliest;
	WeightType Latest;
	int InDegree;
	VNode():FirstEdge(NULL),Earliest(0),Latest(Inf), InDegree(0){}
}PtrToLNodeArr[Maxsize];

struct LNode {
	Vertex V;
	WeightType Weight;
	WeightType Delay;
	PtrToLNode Next;

};
typedef struct GraphNode* Graph;
struct GraphNode {
	int Nv;
	int Ne;
	PtrToLNodeArr heads;
};

Graph BuildGraph(int N, int M) {
	Graph G = new GraphNode;
	G->Nv = N;
	G->Ne = M;
	Vertex v1, v2;
	WeightType W;
	PtrToLNode tmp;
	for (int i = 1; i <= M; i++) {
		cin >> v1 >> v2 >> W;
		tmp = new LNode;
		tmp->V = v2;
		tmp->Weight = W;
		tmp->Next = G->heads[v1].FirstEdge;
		G->heads[v1].FirstEdge = tmp;
	}
	return G;
}
/*����Ϊ��ͼ*/

/*��������*/

void InDegreeCount(Graph G) {
	/*ͳ�����*/
	PtrToLNode tmp;
	Vertex V,W;
	for (V = 1; V <= G->Nv; V++) {
		tmp = G->heads[V].FirstEdge;
		while (tmp != NULL) {
			W = tmp->V;
			G->heads[W].InDegree++;
			tmp = tmp->Next;
		}
	}
}

int TopSorting(Graph G) {
	InDegreeCount(G);
	queue<Vertex> q;
	stack<Vertex> s;
	Vertex V,W;//�����
	int res = 0;//���
	PtrToLNode tmp;//�߶���ָ��
	for (Vertex V = 1; V <= G->Nv; V++) {//�����Ϊ0�������
		if (G->heads[V].InDegree == 0) {
			q.push(V);
		}
	}
	int Vcount = 0;//����ͳ�����������Ƿ�ʧЧ
	while (q.empty() != 1) {
		V = q.front();
		s.push(V);
		q.pop();//����V
		Vcount++;
		for (tmp = G->heads[V].FirstEdge; tmp != NULL; tmp = tmp->Next) {//��V���ڽӵ���и���
			W = tmp->V;
			G->heads[W].InDegree--;//�������
			if (G->heads[W].InDegree == 0) {
				q.push(W);
			}
			if (G->heads[V].Earliest + tmp->Weight > G->heads[W].Earliest) {
				G->heads[W].Earliest = G->heads[V].Earliest + tmp->Weight;//����W������ʱ��
			}
		}
	}
	/*�ж����������Ƿ�ʧЧ��û��ʧЧ�ż���������*/
	if (Vcount != G->Nv) {
		res = 0;
		return res;
	}
	InDegreeCount(G);//���¸���һ�����,�ɲ�����һ������Ӱ����

	int MaxTime = 0;
	for (Vertex Vtmp = 1; Vtmp <= G->Nv; Vtmp++) {//�ҵ����нڵ��е�����ʱ��
		MaxTime = MaxTime > G->heads[Vtmp].Earliest ? MaxTime : G->heads[Vtmp].Earliest;
	}
	
	for (Vertex Vtmp = 1; Vtmp <= G->Nv; Vtmp++) {//��ʼ�����нڵ��Latestʱ��ΪMaxTime
		G->heads[Vtmp].Latest = MaxTime;
	}

	while (s.empty() != 1) {//����ջ��˳����з����޸�Latest
		V = s.top();
		s.pop();//���򵯳�V
		for (tmp = G->heads[V].FirstEdge; tmp != NULL; tmp = tmp->Next) {
			W = tmp->V;
			if (G->heads[V].Latest > G->heads[W].Latest - tmp->Weight) {
				G->heads[V].Latest = G->heads[W].Latest - tmp->Weight;//����V���Latest
			}
		}
	}

	for (Vertex Vtmp = 1; Vtmp <= G->Nv; Vtmp++) {//�����б߶������Delay
		tmp = G->heads[Vtmp].FirstEdge;
		while (tmp != NULL) {
			W = tmp->V;
			tmp->Delay = G->heads[W].Latest - (G->heads[Vtmp].Earliest + tmp->Weight);//�����<v,w>��delay
			tmp = tmp->Next;
		}
	}
	return 1;
}

int FindMaxTime(Graph G) {
	int MaxTime = 0;
	for (Vertex Vtmp = 1; Vtmp <= G->Nv; Vtmp++) {
		MaxTime = MaxTime > G->heads[Vtmp].Earliest ? MaxTime : G->heads[Vtmp].Earliest;
	}
	return MaxTime;
}


void DispRes(int res, Graph G) {
	if (res == 0) {
		cout << "0";
	}
	else if (res == 1) {
		int MaxTime = FindMaxTime(G);
		multimap<Vertex, PtrToLNode> path;
		PtrToLNode tmp;//�߶���
		for (Vertex V = 1; V <= G->Nv; V++) {
			tmp = G->heads[V].FirstEdge;
			while (tmp != NULL) {
				if (tmp->Delay == 0) {//�ж��Ƿ��ǹؼ�·��
					path.insert(make_pair(V, tmp));
				}
				tmp = tmp->Next;
			}
		}
		cout << MaxTime << endl;
		for (auto pt = path.begin(); pt != path.end(); pt++) {
			cout << pt->first << "->" << pt->second->V << endl;
		}
	}
}

int main() {
	int N, M;
	cin >> N >> M;
	Graph G= BuildGraph(N, M);
	int res;
	res=TopSorting(G);
	DispRes(res, G);
	return 0;
}