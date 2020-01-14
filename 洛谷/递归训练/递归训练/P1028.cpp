#include<iostream>
using namespace std;
int cnt = 1;
void f(int x) {
	for (int i = 1; i <= x / 2; i++) {
		cnt++;
		f(i);
	}
}


int main() {
	int n;
	cin >> n;
	f(n);
	cout << cnt;
	return 0;
}