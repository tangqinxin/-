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


void ShellSort(int a[],int N) {
	int Sedgewick[] = { 929,505,209,109,41,19,5,1,0 };
	int Si;
	for (Si = 0; Sedgewick[Si] >= N; Si++) {}//思考：这里为什么是>=而不是>? 因为后面的程序直接是i=D,a[i]==a[D],如果正好相等会溢出,因为数组是从a[0]~a[N-1]
	int D, i, j;
	for (D = Sedgewick[Si]; D > 0; D = Sedgewick[++Si]) {
		for (i = D; i < N; i++) {
			int tmp = a[i];
			for (j = i; j >= D&&a[j - D] > tmp;j=j-D) {//思考：这里j>=D,在循环开始的适合正好是a[0]>tmp
				a[j] = a[j - D];
			}
			a[j] = tmp;
		}
	}
}

int main() {
	int N;
	cin >> N;
	GetData(a, N);
	ShellSort(a, N);
	DispArr(a, N);
	return 0;
}