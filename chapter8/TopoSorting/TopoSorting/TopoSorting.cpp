#include<iostream>
#include<queue>
using namespace std;
#define Maxsize 100
/*�������򣬿���ʹ���ڽӱ�ͼ*/
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
	/*����һ����N�����㣬M���ߵ�����ͼ*/
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
		G->Points[v1].FirstEdge = L;//����ͼֻ��¼v1->v2��
	}
	return G;
}

/*��������ؼ�·������*/
void IndegreeCount(Graph G, int InDegree[]) {
	/*ͳ��Gͼ�е���ȣ����д��InDegree[]��*/
	int i, Index;
	PtrToLNode tmp;
	for (int i = 0; i < G->Nv; i++) {//��Nv����ͳ�����
		tmp = G->Points[i].FirstEdge;
		while (tmp != NULL) {
			InDegree[tmp->V]++;//��i����������ڽӽڵ�V�����+1
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
	/*����InDegree�����Ϊ0�ĵ㣬���������
	int ArrSize=GetArrSize(InDegree);
	for (int i = 0; i < ArrSize; i++) {
		if (InDegree[i] == 0) {
			q.push(i);
		}
	}
}
*/
/*��������������*/
int TopSorting(Graph G) {
	int InDegree[Maxsize];//ͳ�����
	int Time[Maxsize];//ͳ�Ƶ�ÿ���ڵ�����ʲôʱ�����
	queue<Vertex> q;
	Vertex V;
	for (int i = 0; i < G->Nv; i++) {
		Time[i] = 0;//��ʼ��Time��InDegree��ÿ���ڵ�
		InDegree[i] = 0;
	}
	IndegreeCount(G, InDegree);//ͳ�����
	
	for (int i = 0; i < G->Nv; i++) {//����InDegree�����Ϊ0�ĵ㣬���������
		if (InDegree[i] == 0) {
			q.push(i);
		}
	}

	PtrToLNode tmp;
	Vertex W;
	int Vcout = 0;//ͳ�Ƶ����˶��ٸ��ڵ㣬�ж����������Ƿ�ʧЧ,����Ӧ��ΪG->Nv����
	while (q.empty() != 1) {
		V = q.front();
		q.pop();//������ǰ�ڵ�V
		Vcout++;
		for (tmp = G->Points[V].FirstEdge; tmp != NULL; tmp = tmp->Next) {
			/*��V���½ڵ�W����и���*/
			W = tmp->V;
			InDegree[W]--;
			if (InDegree[W] == 0) {
				q.push(W);
			}
			if (Time[V] + tmp->weight > Time[W]) {//����ڵ�W��ʱ���V+<v,w>��С����ôѡȡ������Ǹ�
				Time[W] = Time[V] + tmp->weight;
			}
		}
	}

	int MaxTime = 0;
	for (int i = 0; i < G->Nv; i++) {
		MaxTime = Time[i] > MaxTime ? Time[i] : MaxTime;//ѡ��Time[i]������ֵ
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