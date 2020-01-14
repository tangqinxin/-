#include<iostream>
#include<climits>
using namespace std;

int min(int x, int y) {
	return x < y ? x : y;
}
int min3(int x, int y, int z) {
	int res;
	res = x < y ? x : y;
	res = res < z ? res : z;
	return res;
}

int f(int x) {
	if (x == 0)return 0;
	if (x == 1)return INT_MAX-1;
	int res = INT_MAX-1;
	if (x >= 2) {
		res = min((f(x - 2) + 1), res);
	}
	if (x >= 5)
	{
		res = min((f(x - 5) + 1), res);
	}
	if (x >= 7) {
		res = min((f(x - 7) + 1), res);
	}
	return res;
}

int f2(int x) {
	if (x == 0)return 0;
	if (x == 1)return INT_MAX - 1;
	int res = INT_MAX - 1;
	res = min3((f(x - 2) + 1), (f(x - 5) + 1), (f(x - 7) + 1));
	return res;
}


int main() {
	int x;
	cin >> x;
	int* a = new int[x + 1];
	a[0] = 0;
	int index1, index2, index3;
	int val1, val2, val3;
	int res;
	for (int i = 1; i <= x; i++) {
		index1 = i - 2;
		index2 = i - 5;
		index3 = i - 7;
		val1 = (index1 < 0)?(INT_MAX - 1):(a[index1]+1);
		val2 = (index2 < 0) ? (INT_MAX - 1) : (a[index2]+1);
		val3 = (index3 < 0) ? (INT_MAX - 1) : (a[index3]+1);
		a[i] = min3(val1, val2, val3);
	}
	cout << a[x];


	return 0;
}