#include<iostream>
using namespace std;
int digit[100];

int main() {
	int A, B,D;//十进制数
	cin >> A >> B>>D;
	int sum = A + B;//sum为十进制，将其转换为D进制

	int cnt = 0;
	do {
		digit[cnt++] = sum%D;
		sum = sum / D;
	} while (sum!=0);
	for (int i = cnt - 1; i >= 0; i--) {
		cout << digit[i];
	}

	return 0;
}