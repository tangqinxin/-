#include<iostream>
using namespace std;
int n;
int kind = 0;
int method[10];
int totalmethod[60000][10];//3^10=59000

void f(int total, int Hkind) {
	if (Hkind == 10) {
		if (total == n) {
			for (int i = 0; i < 10; i++) {
				totalmethod[kind][i] = method[i];
			}
			kind++;
		}
	}
	else if (Hkind < 10&&total<n) {
		for (int i = 1; i <= 3; i++) {
			method[Hkind] = i;
			f(total + i, Hkind + 1);
		}
	}
}

int main() {
	cin >> n;
	f(0, 0);
	cout << kind <<endl;
	for (int i = 0; i < kind; i++) {
		for (int j = 0; j < 10; j++) {
			cout << totalmethod[i][j] << " ";
		}
		cout << endl;
	}


	return 0;
}