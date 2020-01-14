#include <iostream>
#define MaxN 10001
typedef int element;
element set[MaxN];
typedef element* settype;
using namespace std;

void buildset(settype S,int N) {
	for (int i = 0; i < N; i++) {/*集合中的0下标表示第一台电脑的父节点下标*/
		S[i] = -1;/*每个节点独立*/
	}
}

int findroot(settype S, int index) {
	if (S[index] < 0) return index;
	else {
		return S[index] = findroot(S, S[index]);/*路径压缩*/
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
	S[index2 - 1] = index1 - 1;/*将index2连到index1上*/
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