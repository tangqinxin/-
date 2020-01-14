#include<iostream>
#define Maxsize 10000
using namespace std;
typedef struct GraphNode* Graph;
struct GraphNode {
	int Nv;
	AdjList heads;
};
typedef LNode* PtrToLNode;
struct LNode {
	int val;
	LNode* Next;
};

typedef struct VNode {
	int indegree = 0;
	int H;
	int X;
	PtrToLNode FirstEdge= NULL;
}AdjList[Maxsize];

typedef struct Data {
	int H;
	int X;
}Dataset[Maxsize];

int main() {
	int N;
	cin >> N;
	Graph G = new GraphNode;
	G->Nv = N;
	Dataset D;
	for (int i = 0; i < N; i++) {
		cin >> D[i].X >> D[i].H;
		G->heads[i].X = D[i].X;
		G->heads[i].H = D[i].H;
	}





	return 0;
}

