#include<iostream>
#include<vector>
using namespace std;
#define Maxsize 1000
#define Inf 65535
typedef int Vertex;
typedef pair<int, int> ValInd;
typedef struct ENode* Edge;
typedef Edge PtrToENode;
struct ENode {
	int Index;
	Edge Next;
};

typedef struct VNode {
	int Val;
	int InDegree;
	Edge FirstEdge;
	int flag;
}AdjList[Maxsize];

typedef struct GraphNode* Graph;
struct GraphNode {
	int Nv;
	int Ne;
	AdjList AdjV;
};

Graph BuildGraph(int a[], int N) {
	Graph G = new GraphNode;
	G->Nv = N;
	G->Ne = 0;
	for (int i = 0; i < N; i++) {//填充邻接表头节点信息
		G->AdjV[i].Val = a[i];
		G->AdjV[i].InDegree = 0;
		G->AdjV[i].flag = 0;
		G->AdjV[i].FirstEdge = NULL;
	}
	return G;
}

void InsertPrevPoint(Graph G, int a[], int OughtIndex, int CurIndex,int Index) {
	/*将[OughtIndex,CurIndex)作为Index点的前驱点*/
	Edge E;
	for (int i = OughtIndex; i < CurIndex; i++) {
		E = new ENode;
		E->Index = Index;
		E->Next = G->AdjV[i].FirstEdge;
		G->AdjV[i].FirstEdge = E;
		G->AdjV[Index].InDegree++;
		G->Ne++;
	}
}

void BuildTopGraph(Graph G, int a[], int N) {
	/*用邻接表建立拓扑图*/
	int OughtIndex = 0;//原本的位置
	int CurIndex = 0;//目前的位置
	int PreV = 0;//前面的点
	for (int i = 0; i < N; i++) {
		if (a[i] == -1){
			G->AdjV[i].flag = 1;
			continue;//空位的情况跳过而且flag置1，在后面不参与统计
		}
		OughtIndex = a[i] % N;
		CurIndex = i;
		if (OughtIndex == CurIndex) {
			G->AdjV[i].InDegree = 0;//如果恰好是其所在位置，则入度为0
		}
		else if (OughtIndex < CurIndex) {
			InsertPrevPoint(G, a, OughtIndex, CurIndex, CurIndex);//将[OughtIndex,CurIndex)作为当前点CurIndex的前驱点
		}
		else if (OughtIndex > CurIndex) {
			InsertPrevPoint(G, a, 0, CurIndex, CurIndex);
			InsertPrevPoint(G, a, OughtIndex, N, CurIndex);//将[0,CurIndex)，[OutghtIndex,N)作为当前点CurIndex的前驱点
		}
	}
}

int FindMinIndex(Graph G, int N) {
	/*找到当前图中的入度为0的点中val最小的点的index并返回*/
	int flag=0;//能否找到合适的点
	int index;
	int val=Inf;
	for (int i = 0; i < N; i++) {
		if (G->AdjV[i].flag==0&&G->AdjV[i].InDegree == 0 && G->AdjV[i].Val<val) {//如果入度为0且没有弹出过而且值更小
			val = G->AdjV[i].Val;
			index = i;
			flag = 1;//已经找到了一个点
		}
	}
	if (flag == 1) {
		return index;
	}
	else if (flag == 0) {
		return -1;
	}
}

void DispRes(vector<int> vec) {
	cout << vec[0];
	for (auto iter = vec.begin() + 1; iter != vec.end(); iter++) {
		cout << " "<<*iter;
	}
}

void ReHashing(Graph G,int a[], int N) {
	BuildTopGraph(G, a, N);
	/*拓扑排序后输出*/
	vector<int> res;//记录结果
	int Index;
	int W_ind;
	Edge E;
	while (1) {
		Index = FindMinIndex(G, N);//找到合适的点的下标
		if (Index == -1)break;//找不到合适的点了，说明已经结束了，跳出循环
		G->AdjV[Index].flag = 1;//弹出这个点并标记
		res.push_back(G->AdjV[Index].Val);//计入结果
		E = G->AdjV[Index].FirstEdge;
		while (E != NULL) {//弹出后所有邻接点入度-1
			W_ind = E->Index;
			G->AdjV[W_ind].InDegree--;
			E = E->Next;
		}
	}
	DispRes(res);
}



int main() {
	int A[Maxsize];
	int res[Maxsize];
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	Graph G;
	G=BuildGraph(A, N);
	BuildTopGraph(G, A, N);
	ReHashing(G, A, N);
	return 0;
}