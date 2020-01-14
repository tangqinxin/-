#include <iostream>
#define MaxN 10001
typedef int element;
element set[MaxN];
typedef element* settype;
using namespace std;

void buildset(settype S,int N) {
	for (int i = 0; i < N; i++) {/*�����е�0�±��ʾ��һ̨���Եĸ��ڵ��±�*/
		S[i] = -1;/*ÿ���ڵ����*/
	}
}

int findroot(settype S, int index) {
	if (S[index] < 0) return index;
	else {
		return S[index] = findroot(S, S[index]);/*·��ѹ��*/
	}
}

void check(settype S) {
	int index1, index2;
	int root1, root2;
	cin >> index1 >> index2;
	root1 = findroot(S,index1 - 1);
	root2 = findroot(S, index2 - 1);
	if (root1 == root2) {
		cout << "yes\n";
	}
	else
		cout << "no\n";
}

void connect(settype S) {
	int index1, index2;
	cin >> index1 >> index2;
	S[index2 - 1] = index1 - 1;/*��index2����index1��*/
}

void result(settype S,int N) {
	int count=0;
	for (int i = 0; i < N; i++) {
		if (S[i] == -1)count++;
	}
	if (count == 1)cout << "The network is connected.\n";
	else cout << "There are " << count << " components.\n";
}


int main() {
	int N;
	cin >> N;
	buildset(set, N);
	char ch;
	while (cin >> ch) {
		switch (ch) {
		case'C':
			check(set); continue;
		case'I':
			connect(set); continue;
		case'S':
			result(set,N); break;
		}
	}
	return 0;
}