#include<iostream>
#include<string>
#include<cstring>
using namespace std;
#define maxsize 10005
char s1[maxsize];
char s2[maxsize];
bool hashtable[maxsize] = { false };

int main() {
	cin.getline(s1, maxsize);
	cin.getline(s2, maxsize);
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	for (int i = 0; i < len2; i++) {
		char ch = s2[i];
		hashtable[ch] = true;
	}

	for (int i = 0; i < len1; i++) {
		char ch = s1[i];
		if (hashtable[ch] == false) {
			cout << ch;
		}
	}
	return 0;
}