#include<iostream>
#include<string>
using namespace std;
int main() {
	string eq;
	cin >> eq;
	double cof, constval;
	cof = 0;
	constval = 0;
	int Positive, IsNum;
	Positive = 1;//默认为整数
	IsNum = 1;
	int OnLeft = 1;
	int tempval=0;
	int HasValue = 0;
	char Unknown;
	for (auto ch : eq) {
		if (ch == '+') {
			if (IsNum == 1) { constval += tempval*Positive*(-OnLeft); }
			else {
				cof += tempval*Positive*OnLeft;
			}
			HasValue = 0;
			Positive = 1;
			tempval = 0;
			IsNum = 1;
		}
		if (ch == '-') {
			if (IsNum == 1) { constval += tempval*Positive*(-OnLeft); }
			else {
				cof += tempval*Positive*OnLeft;
			}
			HasValue = 0;
			Positive = -1;
			tempval = 0;
			IsNum = 1;
		}
		if (ch == '=') {
			if (IsNum == 1) { constval += tempval*Positive*(-OnLeft); }
			else {
				cof += tempval*Positive*OnLeft;
			}
			HasValue = 0;
			OnLeft = -1;
			Positive = 1;
			tempval = 0;
			IsNum = 1;
		}
		if (ch >= '0'&&ch <= '9') {
			HasValue = 1;
			tempval = tempval * 10;//进位
			tempval += ch - '0';
		}
		if (ch >= 'a'&&ch <= 'z') {
			if (HasValue == 0)tempval = 1;
			IsNum = 0;
			Unknown = ch;
		}
	}
	if (IsNum == 1) { constval += tempval*Positive*(-OnLeft); }
	else {
		cof += tempval*Positive*OnLeft;
	}
	if (!(constval / cof))printf("%c=0.000",Unknown);
	else printf("%c=%.3f", Unknown, constval / cof);


	return 0;
}