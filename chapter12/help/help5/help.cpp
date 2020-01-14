#include<iostream>
#include<algorithm>
#include<vector>
#define maxsize 10
using namespace std;
int a[maxsize];
int b[maxsize];

void swap(int* a, int * b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int Find(int a[],int N, int val) {
	int pos;
	for (pos = 0; a[pos] != val &&pos < N; pos++) {}
	return pos;
}

void DispArr(int a[], int N) {
	for (int i = 0; i < N; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

int main() {
	int N = maxsize;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	sort(begin(b), end(b));
	int i = 0;
	int pa;
	int pb;
	int count = 0;
	while (i < N) {
		if (a[i] != b[i]) {
			pa = i;
			pb = Find(b, N, a[i]);
			cout << "swap " << a[pa] << " and " << a[pb] << endl;
			swap(&a[pa], &a[pb]);
			DispArr(a, N);
			count++;
		}
		else {
			i++;
		}
	}
	cout << count << endl;
	for (int i = 0; i < N; i++) {
		cout << a[i] << " ";
	}

	return 0;
}