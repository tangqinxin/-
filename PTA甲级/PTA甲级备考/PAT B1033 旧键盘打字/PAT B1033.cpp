#include<iostream>
#include<unordered_map>
#include<string>
#include<locale>
#include<cstring>
using namespace std;
#define maxsize 1000
int hashtable[maxsize];

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	memset(hashtable, 0, sizeof(hashtable));
	for (int i = 0; i < s1.size(); i++) {
		char ch = tolower(s1[i]);
		hashtable[ch] = 1;//¹þÏ£±í±ê¼Ç
	}

	for (int i = 0; i < s2.size(); i++) {
		if (s2[i] >= 'A'&&s2[i] <= 'Z') {
			char ch = tolower(s2[i]);
			if (hashtable[ch] == 0 && hashtable['+'] == 0) {
				cout << s2[i];
			}
		}
		else if (hashtable[s2[i]] == 0) {
			cout << s2[i];
		}
	}
	printf("\n");


	return 0;
}