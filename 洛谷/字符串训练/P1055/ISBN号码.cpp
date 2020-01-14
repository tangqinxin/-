#include<iostream>
using namespace std;
char num[14];

int main() {
	char mod[] = "0123456789X";
	cin >> num;
	int val = 0;
	int mult = 1;
	for (int i = 0; i < 11; i++) {
		if (num[i] == '-')continue;
		val += (num[i] - '0')*mult;
		mult++;
	}
	val = val % 11;
	char rightans = mod[val];
	if (rightans == num[12])cout << "Right";
	else {
		num[12] = rightans;
		cout << num;
	}
	return 0;
}