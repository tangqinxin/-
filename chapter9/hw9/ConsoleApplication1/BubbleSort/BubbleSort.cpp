#include<iostream>
#define MaxSize 100000
int a[MaxSize];
using namespace std;

void GetData(int a[], int N) {
	for (int i = 0; i < N; i++) {
		cin >> a[i];
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

void BubbleSort(int a[], int N) {
	int Flag_IsOrdered = 1;
	for (int i = N - 1; i >= 0; i--) {
		for (int j = 0; j <i; j++) {
			if (a[j] > a[j + 1]) {
				swap(&a[j], &a[j + 1]);
				Flag_IsOrdered = 0;
			}
		}
		if (Flag_IsOrdered == 1) break;//第一次循环就进行判断是否有序，有序就直接跳出
	}
}

int main() {
	int N;
	cin >> N;
	GetData(a, N);
	BubbleSort(a, N);
	DispArr(a, N);
	return 0;
}