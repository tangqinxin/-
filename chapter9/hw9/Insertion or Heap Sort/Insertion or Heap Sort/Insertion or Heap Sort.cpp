#include<iostream>
#define MaxSize 100
typedef enum{Insert,Heap}TYPE;
using namespace std;
int BeforeSort[MaxSize];
int AfterSort[MaxSize];
void GetData(int a[],int N) {
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
}


void InsertSort(int a[], int N, int tmp) {
	/*��a[N]����ӳ����tmp��Ԫ�ؽ��в�������*/
	int i;
	int tval = a[tmp];
	for ( i = tmp; i > 0&&a[i-1]>tval; i--) {
		a[i] = a[i - 1];
	}
	a[i] = tval;
}

void PercDown(int a[], int start, int N) {
	/*����a[]�����Ѷѣ���0~N-1*/
	int tval = a[0];
	int parent, child;
	int beg = start;
	int end = N - 1;
	for (parent = start; parent * 2 + 1 <= end;parent=child) {
		child = parent * 2 + 1;
		if (child != end&&a[child] < a[child + 1]) {
			child++;
		}
		if (a[child] > tval) {
			a[parent] = a[child];
		}
		else
			break;
	}
	a[parent] = tval;
}

void HeapSort(int a[], int N) {
	/*��a[N]���������һ�ֶ�����*/
	int tmp = N - 1;
	for (; a[tmp] > a[tmp - 1]; tmp--) {}//����ѭ��ʱ,a[tmp]������ģ�Ҫ���滻
	int tval = a[tmp];
	a[tmp] = a[0];
	a[0] = tval;
	PercDown(a, 0, tmp);//���������ѣ��ѵĹ�ģ����tmp����Ϊ��a[tmp]�Ѿ��������
}

TYPE InsertOrHeap(int b[], int a[],int N) {
	/*�ж��ǲ��뻹�Ƕ�����,������ǰ�����򣬺�������ǰ����ͬ;�������Ǻ�������ǰ�治һ����ͬ*/
	/*b[]Ϊ����ǰ���У�a[]Ϊ���������*/
	int tmp=0;
	TYPE T=Insert;
	for (int i = 0; i < N - 1; i++) {
		if (a[i] > a[i + 1]) {
			tmp = i+1;//tmpָ�������Ԫ��
			break;
		}
	}
	for (int i = tmp; i < N; i++) {
		if (b[i] != a[i]) {
			T = Heap;//������沿�ֲ���ͬ�Ļ�����heapsort;ѭ�����������Ļ�����insertsort;
			break;
		}
	}
	/*��һ�ֵ���*/
	if (T == Insert) {
		InsertSort(a, N, tmp);
	}
	if (T == Heap) {
		HeapSort(a, N);
	}

	return T;
}

void DispArr(int a[], int N) {
	for (int i = 0; i < N - 1; i++) {
		cout << a[i] << " ";
	}
	cout << a[N - 1];
}


int main() {
	int N;
	cin >> N;
	GetData(BeforeSort, N);
	GetData(AfterSort, N);
	TYPE IorH=InsertOrHeap(BeforeSort, AfterSort, N);
	if (IorH == Heap) {
		cout << "Heap Sort\n";
	}
	else {
		cout << "Insertion Sort\n";
	}
	DispArr(AfterSort, N);

	return 0;
}