#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int cnt = 0;
	while (n != 1) {
		cnt++;
		n % 2 == 0 ? n = n / 2 : n =( 3 * n + 1)/2;
	}
	cout << cnt;

	return 0;
}