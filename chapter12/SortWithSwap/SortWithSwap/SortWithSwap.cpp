#include<iostream>
#define Maxsize 100000
int A[Maxsize];
using namespace std;

int CountLoop(int a[], int i,int N) {
	/*计算a[]的第i个元素的环*/
	int flag = 0;//环里面是否含有0
	int NextIndex, CurIndex;
	int count = 0;//count统计点的个数
	CurIndex = i;
	if (a[CurIndex] == CurIndex)return 0;
	while (a[CurIndex] != CurIndex) {
		if (a[CurIndex] == 0)flag = 1;
		NextIndex = a[CurIndex];
		a[CurIndex] = CurIndex;
		CurIndex = NextIndex;
		count++;
	}
	if (flag == 1)return count-1;
	if (flag == 0)return count+1;

}

int TimesOfSwap(int a[], int N) {
	int res = 0;
	for (int i = 0; i < N; i++) {
		res += CountLoop(a, i,N);
	}
	return res;
}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	cout << TimesOfSwap(A, N);
	return 0;
}