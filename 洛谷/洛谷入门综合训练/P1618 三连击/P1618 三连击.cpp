#include<iostream>
using namespace std;

void GetDigit3(int num,int bucket[], int start,int end) {
	for (int i = end; i>=start ; i--) {
		bucket[i] = num % 10;
		num = num / 10;
	}
}

int main() {
	float a, b, c;
	cin >> a >> b >> c;
	c = c / a;
	b = b / a;
	int x, y, z;
	int xmax = 999 / c;
	int bucket[9];
	int sum = 0;
	int multi = 1;
	bool flag = 0;
	for (int x = 123; x <= xmax; x++) {
		sum = 0;
		multi = 1;
		y = x*b;
		z = x*c;
		GetDigit3(x, bucket, 0, 2);
		GetDigit3(y, bucket, 3, 5);
		GetDigit3(z, bucket, 6, 8);
		for (int i = 0; i < 9; i++) {
			sum += bucket[i];
			multi *= bucket[i];
		}
		if (sum == 45 && multi == 362880) {
			cout << x << " " << y << " " << z << endl;
			flag = 1;
		}
	}
	if (flag == 0)cout << "No!!!";

	return 0;
}