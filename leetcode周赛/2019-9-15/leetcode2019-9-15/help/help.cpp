#include<iostream>
using namespace std;
struct door {
	int a;
	int b;
};

int main() {
	int n, m;
	cin >> n >> m;
	int temp;
	auto D = new door[n];
	for (int i = 0; i < n; i++) {
		cin >> D[i].a >> D[i].b;
		if (D[i].a > D[i].b) {
			temp = D[i].b;
			D[i].b = D[i].a;
			D[i].a = temp;
		}
	}
	int count = 0;
	int ball;

	for (int i = 0; i < m; i++) {
		cin >> ball;
		for (int j = 0; j < n; j++) {
			if (ball >= D[j].a&&ball <= D[j].b) {
				count++;
				break;
			}
		}
	}
	cout << count;
	return 0;
}