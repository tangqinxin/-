#include<iostream>
using namespace std;

char sentence[100];
char words[100][100];

int main() {
	int cnt = 0;
	while (cin>>words[cnt]) {
		cnt++;
	}
	for (int i = cnt - 1; i >= 0; i--) {
		cout << words[i];
		if (i > 0) cout << " ";
	}

	return 0;
}