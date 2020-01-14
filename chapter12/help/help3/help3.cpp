#include<iostream>
#define Maxsize 10001
int visit[Maxsize];
int a[Maxsize];
using namespace std;

int CountLoop(int a[], int visit[], int pos) {
	int cur = pos;
	int next = a[cur];
	int count = 0;
	while (visit[cur]!=1) {
		visit[cur] = 1;
		cur = next;
		next = a[cur];
		count++;
	}
	return count-1;
}

int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= Maxsize; i++) {
		visit[i] = 0;
	}
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
	}
	int count = 0;
	for (int i = 1; i <= N; i++) {
		if (a[i] == i) {
			visit[i] = 1;
		}
		else if(visit[i]!=1){
			count += CountLoop(a, visit, i);
		}
	}
	cout << count;
	return 0;
}