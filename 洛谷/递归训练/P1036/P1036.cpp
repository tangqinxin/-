#include<iostream>
#include<math.h>
using namespace std;

int isprime(int x) {
	int n = sqrt(double(x));
	for (int i = 2; i <= n; i++) {
		if (x%i == 0)return 0;
	}
	return 1;
}

int count(int a[],int leftnum,int alreadysum,int start,int end){
	if (leftnum == 0) return isprime(alreadysum);
	int sum = 0;

	for (int i = start; i <= end; i++) {
		sum += count(a, leftnum - 1, alreadysum + a[i], i + 1, end);
	}
	return sum;
}


int main() {
	int n, k;
	cin >> n >> k;
	int* a = new int[n];
	for (int i = 0; i < n; i++)cin >> a[i];
	cout << count(a,k, 0, 0, n - 1);
	return 0;
}