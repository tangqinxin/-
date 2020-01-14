#include<iostream>
#include<cstring>
using namespace std;

int main() {
	int que[105];
	int n, m;
	cin >> n >> m;
	memset(que, 0, sizeof(que));
	int count = 0;
	int cur = 1;
	for (int i = 1; count != n; i++) {
		if (que[i] == 1) {
		}
		else if (cur != m) {
			cur++;
		}
		else if (que[i] == 0 && cur == m) {
			cout << i << " ";
			cur = 1;
			que[i] = 1;
			count++;
		}
		if (i == n) {
			i = 0;
		}
	}
	return 0;
}