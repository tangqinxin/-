#include<iostream>
#include<string>
using namespace std;
#define maxsize 1000
int hashtable1[maxsize];
int hashtable2[maxsize];
int visited[maxsize];
int main() {
	string s1;
	string s2;
	cin >> s1 >> s2;
	for (int i = 0; i < s1.size(); i++) {
		char ch = s1[i];
		hashtable1[ch]++;
	}
	for (int i = 0; i < s2.size(); i++) {
		char ch = s2[i];

		hashtable2[ch]++;
	}
	int cnt=0;
	bool canbuy = true;
	for (int i = 0; i < s2.size(); i++) {
		char ch = s2[i];
		if (hashtable2[ch] > hashtable1[ch]&&visited[ch]==0) {
			canbuy = false;
			visited[ch] = 1;
			cnt += hashtable2[ch] - hashtable1[ch];
		}
	}
	if (canbuy == true) {
		cout << "Yes " << s1.size() - s2.size();
	}
	else {
		cout << "No " << cnt;
	}

	return 0;
}