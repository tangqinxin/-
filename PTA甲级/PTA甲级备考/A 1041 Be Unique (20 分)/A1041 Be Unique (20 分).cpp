#include<iostream>
#include<cstdio>
using namespace std;

#define maxsize 100005
int a[maxsize];
int hashtable[maxsize];
#pragma warning(disable:4996)

int main() {
	bool flag = false;
	int ans;
	int n;
	scanf("%d", &n);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);
		if (hashtable[num] == 0) {
			a[cnt]=num;
			cnt++;
		}
		hashtable[num]++;
	}

	for (int i = 0; i < cnt; i++) {
		if (hashtable[a[i]] == 1) {
			flag = true;
			ans = a[i];
			break;
		}
	}

	if (flag == true) {
		cout << ans;
	}
	else if (flag == false) {
		cout << "None";
	}

	return 0;
}