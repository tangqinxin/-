#include<iostream>
#define maxsize 100000
using namespace std;
void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void disparr(int a[], int left, int right) {
	for (int i = left; i <= right; i++)
		cout << a[i] << " ";
}

void qsort(int a[], int left, int right) {
	/*[left,right]*/
	if (left>=right)return;
	disparr(a, left, right); cout << endl;
	int pick = a[left];
	int i, j;
	i = left + 1; j = right;
	while (1) {
		while (a[i] <= pick) {
			i++;
		}
		while (a[j] > pick) {
			j--;
		}
		if (i < j) {
			swap(a + i, a + j);
		}
		else {
			break;
		}
	}
	swap(a + j, a+left);
	disparr(a, left, right); cout << endl << endl;
	qsort(a, left, j - 1);
	qsort(a, j + 1, right);
}

int main() {
	int N;
	cin >> N;
	int a[maxsize];
	for (int i = 0; i < N; i++) { cin >> a[i]; }
	qsort(a, 0, N - 1);
	int isfirst = 0;
	for (int i = 0; i < N; i++) {
		cout << a[i] << " ";
	}
	return 0;
}