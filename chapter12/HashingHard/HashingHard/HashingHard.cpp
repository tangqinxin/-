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
	for (int i = 0; i < N; i++) {//����ڽӱ�ͷ�ڵ���Ϣ
		G->AdjV[i].Val = a[i];
		G->AdjV[i].InDegree = 0;
		G->AdjV[i].flag = 0;
		G->AdjV[i].FirstEdge = NULL;
	}
	return G;
}

void InsertPrevPoint(Graph G, int a[], int OughtIndex, int CurIndex,int Index) {
	/*��[OughtIndex,CurIndex)��ΪIndex���ǰ����*/
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
	/*���ڽӱ�������ͼ*/
	int OughtIndex = 0;//ԭ����λ��
	int CurIndex = 0;//Ŀǰ��λ��
	int PreV = 0;//ǰ��ĵ�
	for (int i = 0; i < N; i++) {
		if (a[i] == -1){
			G->AdjV[i].flag = 1;
			continue;//��λ�������������flag��1���ں��治����ͳ��
		}
		OughtIndex = a[i] % N;
		CurIndex = i;
		if (OughtIndex == CurIndex) {
			G->AdjV[i].InDegree = 0;//���ǡ����������λ�ã������Ϊ0
		}
		else if (OughtIndex < CurIndex) {
			InsertPrevPoint(G, a, OughtIndex, CurIndex, CurIndex);//��[OughtIndex,CurIndex)��Ϊ��ǰ��CurIndex��ǰ����
		}
		else if (OughtIndex > CurIndex) {
			InsertPrevPoint(G, a, 0, CurIndex, CurIndex);
			InsertPrevPoint(G, a, OughtIndex, N, CurIndex);//��[0,CurIndex)��[OutghtIndex,N)��Ϊ��ǰ��CurIndex��ǰ����
		}
	}
}

int FindMinIndex(Graph G, int N) {
	/*�ҵ���ǰͼ�е����Ϊ0�ĵ���val��С�ĵ��index������*/
	int flag=0;//�ܷ��ҵ����ʵĵ�
	int index;
	int val=Inf;
	for (int i = 0; i < N; i++) {
		if (G->AdjV[i].flag==0&&G->AdjV[i].InDegree == 0 && G->AdjV[i].Val<val) {//������Ϊ0��û�е���������ֵ��С
			val = G->AdjV[i].Val;
			index = i;
			flag = 1;//�Ѿ��ҵ���һ����
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
	/*������������*/
	vector<int> res;//��¼���
	int Index;
	int W_ind;
	Edge E;
	while (1) {
		Index = FindMinIndex(G, N);//�ҵ����ʵĵ���±�
		if (Index == -1)break;//�Ҳ������ʵĵ��ˣ�˵���Ѿ������ˣ�����ѭ��
		G->AdjV[Index].flag = 1;//��������㲢���
		res.push_back(G->AdjV[Index].Val);//������
		E = G->AdjV[Index].FirstEdge;
		while (E != NULL) {//�����������ڽӵ����-1
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