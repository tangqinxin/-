#include<iostream>
using namespace std;
int total=1;

void f(int x) {//��ʵ����һ��DFSģ�壬��total����һ���������
	total++;
	for (int i = 1; i <= x / 2; i++) {
		f(i);
	}
}

int f2(int x) {
	if (x == 0)return 0;
	if (x == 1) return 1;
	for (int i = 1; i <= x / 2; i++) {
		total += f2(i);
	}
}

int main() {
	int n;
	cin >> n;
	f2(n);
	cout << total;

	return 0;
}