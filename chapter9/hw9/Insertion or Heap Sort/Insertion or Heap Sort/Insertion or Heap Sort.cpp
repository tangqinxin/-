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
	/*对a[N]数组从抽出第tmp个元素进行插入排序*/
	int i;
	int tval = a[tmp];
	for ( i = tmp; i > 0&&a[i-1]>tval; i--) {
		a[i] = a[i - 1];
	}
	a[i] = tval;
}

void PercDown(int a[], int start, int N) {
	/*数组a[]整最大堆堆，从0~N-1*/
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
	/*对a[N]数组进行下一轮堆排序*/
	int tmp = N - 1;
	for (; a[tmp] > a[tmp - 1]; tmp--) {}//结束循环时,a[tmp]是无序的，要被替换
	int tval = a[tmp];
	a[tmp] = a[0];
	a[0] = tval;
	PercDown(a, 0, tmp);//交换后整堆，堆的规模就是tmp，因为第a[tmp]已经整理过了
}

TYPE InsertOrHeap(int b[], int a[],int N) {
	/*判断是插入还是堆排序,插入是前面有序，后面排序前后相同;堆排序是后面有序，前面不一定相同*/
	/*b[]为排序前序列，a[]为排序后序列*/
	int tmp=0;
	TYPE T=Insert;
	for (int i = 0; i < N - 1; i++) {
		if (a[i] > a[i + 1]) {
			tmp = i+1;//tmp指向无序的元素
			break;
		}
	}
	for (int i = tmp; i < N; i++) {
		if (b[i] != a[i]) {
			T = Heap;//如果后面部分不相同的话，是heapsort;循环正常结束的话就是insertsort;
			break;
		}
	}
	/*下一轮迭代*/
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