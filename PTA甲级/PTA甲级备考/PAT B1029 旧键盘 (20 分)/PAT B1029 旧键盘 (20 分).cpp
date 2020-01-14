#include<iostream>
#include<unordered_map>
#include<string>
#include<locale>
using namespace std;

int main() {
	string s1;
	string s2;
	cin >> s1 >> s2;
	unordered_map<char, int> mp1;
	unordered_map<char, int> mp2;
	unordered_map<char, bool> visited;
	for (int i = 0; i < s1.size(); i++) {
		char c1 = toupper(s1[i]);
		mp1[c1] = 2;
	}
	for (int i = 0; i < s2.size(); i++) {
		char c2 = toupper(s2[i]);
		mp2[c2] = 2;
		visited[c2] = false;//初始化为没有访问过
	}
	for (int i = 0; i < s1.size(); i++) {
		char c1 = toupper(s1[i]);
		if (mp2[c1] != 2 && visited[c1] == false) {
			cout << c1;
			visited[c1] = true;//设置为访问过
		}
	}

	return 0;
}