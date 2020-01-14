#include<iostream>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	int c = a + b;
	int output[10];
	bool isposi = true;
	if (c < 0) {
		isposi = false;
	}
	int num = c % 10;
	int pos = 0;
	output[pos] = num;
	while (c / 10 != 0) {
		pos++;
		c = c / 10;
		num = c % 10;
		output[pos] = num;
	}
	if (isposi == false) {
		cout << "-";
	}
	int count = 0;
	while (pos>=0) {
		
	}
	return 0;
}