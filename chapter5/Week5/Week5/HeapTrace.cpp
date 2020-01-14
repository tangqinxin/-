#include <iostream>
#define MaxN 10001
#define Min -10001
using namespace std;
typedef struct HeapNode* Heap;
struct HeapNode {
	int size;
	int data[MaxN];
	HeapNode() :data{ Min },size(0) {}
};

/*������С��*/
void insert(Heap H, int x) {
	if (H->size>= MaxN) return;
	else {
		H->size++;
		int i = H->size;
		H->data[i] = x;
		for (i = H->size; H->data[i / 2]>x; i = i / 2) {
			H->data[i] = H->data[i / 2];
		}
		H->data[i] = x;
	}
}

void Trace(Heap H, int num) {
	if (num <= 0) return;
	else {
		int i = num;
		for (; i >= 1; i = i / 2) {
			if (i > 1) cout << H->data[i] << " ";
			else if (i == 1) cout << H->data[i];
		}
	}
}

int main() {
	/*����в���Ԫ��*/
	/*��ӡ��Ӧ�±�ĸ��ڵ��ϵ�·��*/

	int N, M, x,num;
	cin >> N >> M;	/*����N��M*/
	Heap H=new HeapNode;	/*����һ����*/
	for (int i = 0; i < N; i++) {
		cin >> x;
		insert(H, x);
	}

	for (int i = 0; i < M; i++) {
		cin >> num;
		Trace(H, num);
		cout << endl;
	}

	return 0;
}