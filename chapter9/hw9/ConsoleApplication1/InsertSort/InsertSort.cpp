#include <iostream>
#define MaxSize 100000
int a[MaxSize];
using namespace std;

void GetData(int a[], int N) {
	for (int i = 0; i < N; i++) {
		cin >> a[i];//�������ݲ���Ҫ����
	}
}

void swap(int* val1, int* val2) {
	int tmp = *val1;
	*val1 = *val2;
	*val2 = tmp;
}

void DispArr(int a[], int N) {
	cout << a[0];
	N--;
	int i = 1;
	while (N--) {
		cout << " " << a[i++];
	}
}

void InsertSort(int a[], int N) {
	int item;
	int i, j;
	for (i = 1; i < N; i++) {
		item = a[i];//�����Ԫ��
		for (j = i; j > 0&&item<a[j-1]; j--) {
			a[j] = a[j - 1];
		}//������ѭ��ʱ��Ҫô��ͷ��,j=0��Ҫôj-1���itemҪС,��ʱ��item��ֵ��a[j]����
		a[j] = item;
	}
}

void InsertSort2(int a[], int N) {
	int item;
	int i, j;
	for (i = 1; i < N; i++) {
		for (j = i; j > 0; j--) {
			if (a[j] < a[j - 1]) swap(&a[j], &a[j - 1]);
			else break;
		}
	}
}

int main() {
	int N;
	cin >> N;
	GetData(a, N);
	InsertSort2(a, N);
	DispArr(a, N);
	return 0;
}