#include<iostream>
#include<algorithm>
using namespace std;
struct apple {
	int x;
	int y;
};

bool cmp(apple a1, apple a2) {
	return a1.y < a2.y;
}

int main() {
	int n, s;
	int a, b;
	cin >> n >> s;
	cin >> a >> b;
	auto apples = new apple[n];
	for (int i = 0; i < n; i++) {
		cin >> apples[i].x >> apples[i].y;
	}
	int count = 0;
	sort(apples, apples + n, cmp);
	for (int i = 0; i < n; i++) {
		if (s - apples[i].y >= 0 && (a + b >= apples[i].x)) {
			count++;
			s = s - apples[i].y;
		}
	}
	cout << count;
	return 0;
}