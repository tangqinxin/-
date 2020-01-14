#include <iostream>
#include<queue>
using namespace std;
typedef int weight;
typedef int Vertex;
typedef int datatype;
#define MaxN 10
queue<int> output;
/*------------------���ڽӱ�ͼ-----------------------*/

struct LNode {
	Vertex v;
	weight w;
	LNode* NextNode;
	LNode():NextNode(NULL){}
};
typedef LNode* Llist;
/*���ﶨ����2���������ͣ�һ����LHeadNode,һ����LHeadList*/
typedef struct LHeadNode {
	datatype data;
	Llist FirstLNode;
}LHeadList[MaxN];


struct LGraphNode {
	int nv;
	int ne;
	LHeadList LM;
};
typedef LGraphNode* LGraph;


LGraph buildLgraph(int N) {
	LGraph L = new LGraphNode;
	L->ne = 0;
	L->nv = N;
	for (int i = 0; i < L->nv; i++) {
		L->LM[i].FirstLNode=NULL;
	}
	return L;
}

void LInsertEdge(LGraph Lmap, Vertex v1, Vertex v2) {
	Lmap->ne++;
	Llist newnode = new LNode;
	newnode->v = v2;
	newnode->NextNode = Lmap->LM[v1].FirstLNode;
	Lmap->LM[v1].FirstLNode = newnode;

	Llist newnode2 = new LNode;
	newnode2->v = v1;
	newnode2->NextNode = Lmap->LM[v2].FirstLNode;
	Lmap->LM[v2].FirstLNode = newnode2;
}

/*�������LBFS���ڲ���Ĺ���������ģ���������ʱ����ܲ����Ѻã��ﲻ����Ŀ�Ǹ�Ч��*/
void LBFS(LGraph Lmap, Vertex v, int visit[]) {
	int N = Lmap->nv;
	if (visit[v] != 1) {
		output.push(v);
		visit[v] = 1;
		cout << " " << v;
	}
	while (!output.empty()) {
		Vertex v2 = output.front();
		output.pop();
		/*�ڽӱ���ص���ֻ�洢�����Ľڵ㣬����������û����Ϣ�ģ���������ϵĶ��������Ľڵ㣻���⻹��Ҫ�ж���Щ�Ƿ��ʹ���*/
		for (Llist Lptr = Lmap->LM[v2].FirstLNode; Lptr!= NULL; Lptr = Lptr->NextNode) {
			if (visit[Lptr->v] != 1) {//����������ܼ���ѭ���У���Ϊѭ������������еĽڵ㣬�����Ƿ�����������һ������
				output.push(Lptr->v);
				visit[Lptr->v] = 1;//���Ϊ���ʹ���
				cout << " " << Lptr->v;
			}
		}
	}
}

void LDFS(LGraph Lmap, Vertex v, int visit[]) {
	int N = Lmap->nv;
	if (visit[v] != 1) {
		cout << " " << v;
		visit[v] = 1;
	}
	for (auto Lptr = Lmap->LM[v].FirstLNode; Lptr != NULL; Lptr = Lptr->NextNode) {
		if (visit[Lptr->v] != 1) {
			visit[Lptr->v] = 1;
			cout << " " << Lptr->v;
			LDFS(Lmap, Lptr->v, visit);
		}
	}
}


/*-----------------------------------------------------*/
/*1.���ڽӾ���ͼ*/
struct MGraphNode {
	int nv;
	int ne;
	weight G[MaxN][MaxN];
	datatype data[MaxN];
};

typedef MGraphNode* PtrToMGraph;
typedef PtrToMGraph MGraph;

/*����ͼ*/
MGraph buildMgraph(int N) {
	MGraph Gmap= new MGraphNode;
	Gmap->nv = N;
	Gmap->ne = 0;
	for (int i = 0; i < Gmap->nv; i++) {
		for (int j = 0; j < Gmap->nv; j++) {
			Gmap->G[i][j] = 0;/*��ʼ��Ϊ0,��û������*/
		}
	}
	return Gmap;
}

/*�����*/
void InsertEdge(MGraph Gmap, Vertex v1, Vertex v2) {
	Gmap->ne++;
	Gmap->G[v1][v2] = 1;
	Gmap->G[v2][v1] = 1;
}



/*��ʼ�����ʼ�¼*/
int visit[MaxN];
void reset(int a[],int N) {
	for (int i = 0; i < N; i++) {
		a[i] = 0;
	}
}

/*DFS�ӽڵ�v��ʼ����*/
void DFS(MGraph Gmap,Vertex v,int visit[]) {
	int N = Gmap->nv;
	if (visit[v] != 1) {
		visit[v] = 1;
		cout <<" "<<v;
	}
	for (int i = 0; i < N; i++) {
		if (Gmap->G[v][i] == 1&&visit[i]!=1) {/*�������ͨ����û�з��ʹ�*/
			DFS(Gmap, i, visit);/*������ʵ�е������������ı�����ֻ�Ƕ��������ÿ��������Ϊ���ұ���������ֱ�ӱ�����*/
		}
	}
}

void BFS(MGraph Gmap, Vertex v, int visist[]) {
	int N = Gmap->nv;
	if (visist[v] != 1) {
		visist[v] = 1;
		output.push(v);
	}

	while (!output.empty()) {
		Vertex v2 = output.front();
		output.pop();
		cout << " " << v2;
		for (int i = 0; i < N; i++) {
			if (Gmap->G[v2][i] == 1 && visist[i] != 1) {/*v2����Χ�������ͨ�Ķ���û�б����ʹ�����ô�ͽ��������в����Ϊ���ʹ�*/
				visist[i] = 1;
				output.push(i);
			}
		}
	}
}



int main() {
	int N, E;
	cin >> N>>E;
	MGraph Gmap = buildMgraph(N);
	Vertex v1, v2;
	for (int i = 0; i < E; i++) {
		cin >> v1 >> v2;
		InsertEdge(Gmap, v1, v2);
	}
	reset(visit, N);
	for (int i = 0; i < N; i++) {
		if (visit[i] != 1) {//ͨ��ѭ����ɨ����ͨ�����ɨ���һ����ͨ��һ���Ƿ��ʹ�����
			cout << "{";
			DFS(Gmap, i, visit);
			cout << " }" << endl;
		}
	}
	reset(visit, N);

	for (int i = 0; i < N; i++) {
		if (visit[i] != 1) {
			cout << "{";
			BFS(Gmap, i, visit);
			cout << " }" << endl;
		}
	}
	return 0;
}

/*
int main() {
	int N, E;
	cin >> N >> E;
	LGraph Lmap = buildLgraph(N);
	Vertex v1, v2;
	for (int i = 0; i < E; i++) {
		cin >> v1 >> v2;
		LInsertEdge(Lmap, v1, v2);
	}
	for (int i = 0; i < N; i++) {
		if (visit[i] != 1) {
			cout << "{";
			LDFS(Lmap, i, visit);
			cout << " }" << endl;
		}
	}
	reset(visit, N);
	for (int i = 0; i < N; i++) {
		if (visit[i] != 1) {
			cout << "{";
			LBFS(Lmap, i, visit);
			cout << " }" << endl;
		}
	}
	return 0;
}
*/