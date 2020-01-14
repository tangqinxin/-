#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	bool IsNagtive = 0;
	if (n < 0) {
		n = -n;
		IsNagtive = 1;
	}
	int ReverseN = 0;
	while (n/10!=0&&n%10==0) {
		n = n / 10;
	}
	while (n) {
		ReverseN = ReverseN * 10;
		ReverseN += n % 10;
		n = n / 10;
	}
	if (IsNagtive) {
		cout << "-" << ReverseN;
	}
	else {
		cout << ReverseN;
	}
	return 0;
}