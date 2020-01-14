#include <iostream>
#define MaxSize 100000
int a[MaxSize];

using namespace std;

void GetData(int a[], int N) {
	for (int i = 0; i < N; i++) {
		cin >> a[i];//这里数据不需要后移
	}
}

void DispArr(int a[], int N) {
	cout << a[0];
	N--;
	int i = 1;
	while (N--) {
		cout << " " << a[i++];
	}
}


int* TSort(int a[], int N) {
	int* table = new int[N];
	for (int i = 0; i < N; i++) {
		table[i] = i;
	}
	int tmp;
	int i, j;
	for (i = 1; i < N; i++) {
		tmp = a[table[i]];
		for (j = i; j> 0 && tmp < a[table[j - 1]];j--) {
			table[j] = table[j - 1];//不对原数组进行操作，只改变指针的内容
		}
		table[j] = i;
	}
	return table;
}


void DispArr2(int a[],int table[], int N) {
	/*对数组a[]，利用table[]表来输出*/
	cout << a[table[0]];
	N--;
	int i = 1;
	while (N--) {
		cout << " " << a[table[i++]];
	}
}

void NodeProcess(int a[], int table[], int head) {
	/*根据数组a[]和table[]来处理head节点的相关环*/
	int tmp = a[head];
	int CurNode =head;
	int NextNode = table[CurNode];
	while (1) {
		if (table[CurNode] == head) {
			a[CurNode] = tmp;/*思考：这里的这两个语句处理能否写成一个函数？*/
			table[CurNode] = CurNode;
			break;
		}
		/*当前节点值改变*/
		a[CurNode] = a[NextNode];
		table[CurNode] = CurNode;
		/*转移到下一个节点*/
		CurNode = NextNode;
		NextNode = table[CurNode];
	}
}

void ChangeArr(int a[], int table[], int N) {
	/*将数组a[]根据表table[]进行交换和修改*/
	for (int i = 0; i < N; i++) {
		if (table[i] != i) {
			NodeProcess(a, table, i);
		}
	}
}

void TableSort(int a[], int N) {
	/*统一函数接口*/
	int* Table = TSort(a, N);
	ChangeArr(a, Table, N);
	delete []Table;
}

int main() {
	int N;
	cin >> N;
	GetData(a, N);
	/* 未统一接口的函数
	int* Table=TSort(a, N);
	DispArr2(a,Table,N);*/
	TableSort(a, N);
	DispArr(a, N);
	return 0;
}