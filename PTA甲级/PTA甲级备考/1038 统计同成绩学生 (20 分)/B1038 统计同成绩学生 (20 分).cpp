#include<iostream>
#include<cstring>
using namespace std;
int hashtable[105];
#pragma warning(disable: 4996)  
int main() {

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int mark;
		scanf("%d", &mark);
		hashtable[mark]++;
	}
	int n2;
	cin >> n2;
	for (int i = 1; i <= n2; i++) {
		int mark;
		scanf("%d", &mark);
		printf("%d",hashtable[mark]);
		if (i != n2)cout << " ";
	}

	return 0;
}