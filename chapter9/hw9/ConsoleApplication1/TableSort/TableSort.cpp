#include <iostream>
#define MaxSize 100000
int a[MaxSize];

using namespace std;

void GetData(int a[], int N) {
	for (int i = 0; i < N; i++) {
		cin >> a[i];//�������ݲ���Ҫ����
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
			table[j] = table[j - 1];//����ԭ������в�����ֻ�ı�ָ�������
		}
		table[j] = i;
	}
	return table;
}


void DispArr2(int a[],int table[], int N) {
	/*������a[]������table[]�������*/
	cout << a[table[0]];
	N--;
	int i = 1;
	while (N--) {
		cout << " " << a[table[i++]];
	}
}

void NodeProcess(int a[], int table[], int head) {
	/*��������a[]��table[]������head�ڵ����ػ�*/
	int tmp = a[head];
	int CurNode =head;
	int NextNode = table[CurNode];
	while (1) {
		if (table[CurNode] == head) {
			a[CurNode] = tmp;/*˼�����������������䴦���ܷ�д��һ��������*/
			table[CurNode] = CurNode;
			break;
		}
		/*��ǰ�ڵ�ֵ�ı�*/
		a[CurNode] = a[NextNode];
		table[CurNode] = CurNode;
		/*ת�Ƶ���һ���ڵ�*/
		CurNode = NextNode;
		NextNode = table[CurNode];
	}
}

void ChangeArr(int a[], int table[], int N) {
	/*������a[]���ݱ�table[]���н������޸�*/
	for (int i = 0; i < N; i++) {
		if (table[i] != i) {
			NodeProcess(a, table, i);
		}
	}
}

void TableSort(int a[], int N) {
	/*ͳһ�����ӿ�*/
	int* Table = TSort(a, N);
	ChangeArr(a, Table, N);
	delete []Table;
}

int main() {
	int N;
	cin >> N;
	GetData(a, N);
	/* δͳһ�ӿڵĺ���
	int* Table=TSort(a, N);
	DispArr2(a,Table,N);*/
	TableSort(a, N);
	DispArr(a, N);
	return 0;
}