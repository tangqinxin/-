#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#define Maxsize 10001
using namespace std;

typedef struct LNode* PtrToNode;
struct LNode {
	int index;
	PtrToNode Next;
};

typedef struct VNode AdjList[Maxsize];
struct VNode {
	int val;
	PtrToNode FirstEdge;
	VNode():FirstEdge(NULL){}
};

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	int N, K, S;
	cin >> N >> K >> S;
	/*建图*/
	int v1, v2;
	AdjList G;
	for (int i = 1; i < N; i++) {
		cin >> v1 >> v2;
		PtrToNode tmp = new LNode;
		tmp->index = v2;
		tmp->Next = G[v1].FirstEdge;
		G[v1].FirstEdge = tmp;
	}

	for (int i = 1; i <= N; i++) {
		cin >> G[i].val;
	}
	/*遍历*/
	PtrToNode temp;
	queue<PtrToNode> q;
	vector<int> vec;
	vector<int> res;
	int v, val,size;
	int sum = 0;
	for (int i = 1; i <= N; i++) {
		temp = G[i].FirstEdge;
		while (temp != NULL) {
			q.push(temp);
			temp = temp->Next;//将第一层全部入队
		}
		while (!q.empty()) {
			temp = q.front();
			q.pop();
			v = temp->index;
			val = G[v].val;
			vec.push_back(val);
			temp = G[v].FirstEdge;
			while (temp!= NULL) {
				q.push(temp);
				temp = temp->Next;
			}
		}
		sort(vec.begin(), vec.end(),cmp);
		size = vec.size();
		for (int i = 0; i<size &&i < K; i++) {
				sum += vec[i];
		}
		if (size >= K) {
			res.push_back(sum);
		}
		else {
			sum += G[i].val;
			res.push_back(sum);
		}
		sum = 0;
		vec.clear();
	}
	for (int i = 1; i <= N; i++) {
		cout << res[i - 1] << endl;
	}

	return 0;
}