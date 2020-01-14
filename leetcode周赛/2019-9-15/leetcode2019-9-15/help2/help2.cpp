#include<iostream>
#include<cstring>
using namespace std;

int main() {
	int door[1001];
	memset(door, 0, sizeof(door));
	int n, m;
	cin >> n >> m;
	int a, b;
	int val = -1;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		memset(door + a, val, sizeof(int)*(b - a + 1));
	}
	int ball;
	int count = 0;
	for (int i = 0; i < m; i++) {
		cin >> ball;
		if (door[ball] == -1)count++;
	}
	cout << count;
	return 0;
}