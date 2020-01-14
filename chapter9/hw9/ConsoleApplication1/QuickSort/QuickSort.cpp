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

void swap(int* val1, int* val2) {
	int tmp = *val1;
	*val1 = *val2;
	*val2 = tmp;
}

int Median3(int a[], int left, int right) {
	/*对数组a[],在a[left],a[right],a[center]中进行排序,返回中位数作为pivot*/
	int center = (left + right) / 2;
	if (a[left] > a[center]) swap(&a[left], &a[center]);
	if (a[left] > a[right]) swap(&a[left], &a[right]);
	if (a[center] > a[right]) swap(&a[center], &a[right]);
	/*将a[center]藏到a[right-1]*/
	swap(&a[center], &a[right - 1]);
	return a[right - 1];
}

void QSort(int a[], int left, int right) {
	if (left >= right) return;
	int pivot = Median3(a, left, right);
	int low, high;
	low = left;
	high = right - 2;
		while (low <= high) {
			if (a[low] >= pivot) {
				if (a[high] <= pivot) {
					swap(&a[low], &a[high]); high--; low++;
				}
				else high--;
			}
			else low++;
		}
		swap(&a[low], &a[right - 1]);
		QSort(a, left, low - 1);
		QSort(a, low + 1, right);
}

void QSort2(int a[], int left, int right) {
	if (left >= right) return;
	/*对数组a[],在[left,right]区间进行快速排序*/
	int pivot = Median3(a, left, right);
	int low = left;
	int high = right - 1;
	while (1) {
		while (a[++low] < pivot);//退出循环时a[low]>=pivot
		while (a[--high] > pivot);//退出循环时a[high]<=pivot
		if (high > low)swap(&a[low], &a[high]);
		else break;
	}
	if (low < right - 1) {
		swap(&a[low], &a[right - 1]);
	}
	QSort2(a, left, low - 1);
	QSort2(a, low + 1, right);
}

void InsertSort(int a[], int N) {
	int tmp;
	int i, j;
	for (i = 1; i < N; i++) {
		tmp = a[i];
		for ( j = i; j > 0; j--) {
			if (tmp < a[j - 1])a[j] = a[j - 1];
			else break;
		}
		a[j] = tmp;
	}
}


void QSort3(int a[], int left, int right) {
	int cutoff = right - left + 1;
	if (cutoff >= 100) {
		/*对数组a[],在[left,right]区间进行快速排序*/
		int pivot = Median3(a, left, right);
		int low = left;
		int high = right - 1;
		while (1) {
			while (a[++low] < pivot);//退出循环时a[low]>=pivot
			while (a[--high] > pivot);//退出循环时a[high]<=pivot
			if (high > low)swap(&a[low], &a[high]);
			else break;
		}
		if (low < right - 1) {
			swap(&a[low], &a[right - 1]);
		}
		QSort3(a, left, low - 1);
		QSort3(a, low + 1, right);
	}
	else {
		InsertSort(a + left, right - left + 1);
	}
}



void QuickSort(int a[], int N) {
	QSort(a, 0, N - 1);
}

void QuickSort2(int a[], int N) {
	QSort2(a, 0, N - 1);
}
void QuickSort3(int a[], int N) {
	QSort3(a, 0, N - 1);
}
int main() {
	int N;
	cin >> N;
	GetData(a, N);
	QuickSort3(a, N);
	DispArr(a, N);
	return 0;
}