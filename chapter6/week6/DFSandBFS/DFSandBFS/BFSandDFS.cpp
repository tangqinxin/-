#include <iostream>
#include<queue>
using namespace std;
typedef int weight;
typedef int Vertex;
typedef int datatype;
#define MaxN 10
queue<int> output;
/*------------------用邻接表建图-----------------------*/

struct LNode {
	Vertex v;
	weight w;
	LNode* NextNode;
	LNode():NextNode(NULL){}
};
typedef LNode* Llist;
/*这里定义了2种数据类型，一个是LHeadNode,一种是LHeadList*/
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

/*这里这个LBFS由于插入的过程是随机的，因此输出的时候可能并不友好，达不到题目那个效果*/
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
		/*邻接表的特点是只存储相连的节点，不相连的是没有信息的，因此链表上的都是相连的节点；另外还需要判断哪些是访问过的*/
		for (Llist Lptr = Lmap->LM[v2].FirstLNode; Lptr!= NULL; Lptr = Lptr->NextNode) {
			if (visit[Lptr->v] != 1) {//这个条件不能加在循环中，因为循环必须遍历所有的节点，但是是否加入是另外的一个问题
				output.push(Lptr->v);
				visit[Lptr->v] = 1;//标记为访问过了
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
/*1.用邻接矩阵建图*/
struct MGraphNode {
	int nv;
	int ne;
	weight G[MaxN][MaxN];
	datatype data[MaxN];
};

typedef MGraphNode* PtrToMGraph;
typedef PtrToMGraph MGraph;

/*矩阵建图*/
MGraph buildMgraph(int N) {
	MGraph Gmap= new MGraphNode;
	Gmap->nv = N;
	Gmap->ne = 0;
	for (int i = 0; i < Gmap->nv; i++) {
		for (int j = 0; j < Gmap->nv; j++) {
			Gmap->G[i][j] = 0;/*初始化为0,即没有连线*/
		}
	}
	return Gmap;
}

/*插入边*/
void InsertEdge(MGraph Gmap, Vertex v1, Vertex v2) {
	Gmap->ne++;
	Gmap->G[v1][v2] = 1;
	Gmap->G[v2][v1] = 1;
}



/*初始化访问记录*/
int visit[MaxN];
void reset(int a[],int N) {
	for (int i = 0; i < N; i++) {
		a[i] = 0;
	}
}

/*DFS从节点v开始遍历*/
void DFS(MGraph Gmap,Vertex v,int visit[]) {
	int N = Gmap->nv;
	if (visit[v] != 1) {
		visit[v] = 1;
		cout <<" "<<v;
	}
	for (int i = 0; i < N; i++) {
		if (Gmap->G[v][i] == 1&&visit[i]!=1) {/*如果有联通并且没有访问过*/
			DFS(Gmap, i, visit);/*这里其实有点像二叉树里面的遍历，只是二叉树里把每个遍历分为左右遍历，这里直接遍历了*/
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
			if (Gmap->G[v2][i] == 1 && visist[i] != 1) {/*v2点周围如果是连通的而且没有被访问过，那么就将其加入队列并标记为访问过*/
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
		if (visit[i] != 1) {//通过循环来扫描连通域，如果扫描过一次连通域一定是访问过的了
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