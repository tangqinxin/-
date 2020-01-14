#include<iostream>
using namespace std;

int f(char a[]) {
	int res = 1;
	for (int i = 0; a[i] != '\0'; i++) {
		res *= (a[i] - 'A'+1);
	}
	res = res % 47;
	return res;
}

int main() {
	char name1[7];
	char name2[7];
	cin >> name1;
	cin >> name2;
	int n1, n2;
	n1 = f(name1);
	n2 = f(name2);
	n1 == n2 ? cout << "GO" : cout << "STAY";
	return 0;
}