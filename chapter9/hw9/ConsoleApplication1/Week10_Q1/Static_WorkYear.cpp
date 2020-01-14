#include <iostream>
#define MaxSize 100000
#define MaxAge 51
int a[MaxSize];
int res[MaxAge] = {};
using namespace std;

void GetData(int a[],int N) {
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
}

void StaticsArr(int a[], int res[],int N) {
	int Age;
	for (int i = 0; i < N; i++) {
		Age = a[i];
		res[Age]++;
	}
}

void DispRes(int res[]) {
	int i;
	for ( i = 0; i < MaxAge-1; i++) {
		if (res[i] != 0) {
			cout << i << ":" << res[i] << endl;
		}
	}
	if (res[i] != 0) {
		cout << i << ":" << res[i];
	}
}

int InsertOrMerge(int a[],int res[],int N){


}



int main() {
	int N;
	cin >> N;
	GetData(a, N);
	StaticsArr(a, res,N);
	DispRes(res);
	return 0;
}