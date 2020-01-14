#include <iostream>
#define MaxSize 100000
int a[MaxSize];
using namespace std;
void GetData(int a[],int N) {
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
}

int FindMin(int a[], int arr_beg, int arr_end) {
	/*寻找数组a[],从arr_beg到arr_end的最小值，并返回它的下标*/
	int MinPos = arr_beg;
	for (int i = arr_beg; i <= arr_end; i++) {
		MinPos = a[i] < a[MinPos] ? i : MinPos;
	}
	return MinPos;
}

void swap(int* val1, int* val2) {
	int tmp = *val1;
	*val1 = *val2;
	*val2 = tmp;
}

void Sort(int a[],int N) {
	for (int i = 0; i < N; i++) {
		int MinPos = FindMin(a, i, N - 1);
		swap(&a[i], &a[MinPos]);
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

int main() {
	int N;
	cin >> N;
	GetData(a,N);
	Sort(a, N);
	DispArr(a, N);
	return 0;
}