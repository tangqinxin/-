#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
	int n, x;
	cin >> n >> x;
	int count = 0;
	int num;
	int FirstDigit = 0;
	for (int i = 1; i <= n; i++) {
		num = i;
		do {
			FirstDigit = num % 10;
			if (FirstDigit == x)count++;
			num = num / 10;
		} while (num != 0);
	}
	cout << count;

	return 0;
}