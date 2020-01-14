#include <iostream>
using namespace std;
#define MaxSize 100001
int a[MaxSize];

typedef struct HNode* Heap;
struct HNode {
	int* Data;
	int Size;
	int Capacity;
};

typedef Heap MaxHeap;
typedef Heap MinHeap;

void GetData(int a[], int N) {
	for (int i = 0; i < N; i++) {
		cin >> a[i+1];//�����������һ��λ��,�����̣�a[0]Ϊ��
	}
}

void swap(int* val1, int* val2) {
	int tmp = *val1;
	*val1 = *val2;
	*val2 = tmp;
}

void PercDown(int a[], int i, int N) {
	/*������a[],�ӵ�i���ڵ㿪ʼ���ˣ�����Ĺ�ģΪN�������a[1]��ʼ,��������*/
	int MaxNum = a[i];
	int parent, child;
	for (parent = i; parent * 2 <= N;parent=child) {
		child = 2 * parent;
		if (child != N&&a[child] < a[child + 1]) {
			child++;
		}
		if (MaxNum >= a[child]) break;
		else
			a[parent] = a[child];
	}
	a[parent] = MaxNum;
}

void BuildHeap(int a[], int N) {
	/*��������*/
	for (int i = N / 2; i >0; i--) {
		PercDown(a, i, N);
	}
}

void DispArr(int a[], int N) {
	cout << a[1];
	N--;
	int i = 2;
	while (N--) {
		cout << " " << a[i++];
	}
}

void HeapSort(int a[], int N) {
	BuildHeap(a, N);
	for (int i = N; i >0; ) {
		swap(&a[1], &a[i--]);
		PercDown(a, 1, i);
	}
}

int main() {
	int N;
	cin >> N;
	GetData(a, N);
	HeapSort(a, N);
	DispArr(a, N);
	return 0;
}