#include<iostream>
#include<cstdio>
#pragma warning(disable:4996)
using namespace std;
int month[13][2] = { {0,0},{31,31},{28,29},{31,31},{30,30},{31,31},{30,30},{31,31},{31,31},{30,30},{31,31},{30,30},{31,31} };

bool isleap(int year) {
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
		return true;
	}
	return false;
}
int cnt = 1;
int main() {
	int data1;
	int data2;
	//cin >> data1 >> data2;
	while (scanf("%d%d", &data1, &data2) != EOF) {

		if (data1 < data2) {
			int tmp = data1;
			data1 = data2;
			data2 = tmp;//交换两数,使得data1>data2
		}

		int year1, year2;
		int mon1, mon2;
		int day1, day2;

		year1 = data1 / 10000;
		year2 = data2 / 10000;
		mon1 = data1 % 10000 / 100;
		mon2 = data2 % 10000 / 100;
		day1 = data1 % 100;
		day2 = data2 % 100;

		cnt = 1;
		while (year1 != year2 || mon1 != mon2 || day1 != day2) {
			cnt++;
			day2++;
			if (isleap(year2)) {
				if (day2 > month[mon2][1]) {
					mon2++;
					day2 = 1;
				}
			}
			else {
				if (day2 > month[mon2][0]) {
					mon2++;
					day2 = 1;
				}
			}

			if (mon2 > 12) {
				year2++;
				mon2 = 1;
			}
		}
	}
	cout << cnt<<endl;
	return 0;
}