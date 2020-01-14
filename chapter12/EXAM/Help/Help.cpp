#include<iostream>
#include<string>
#include<stack>
#define Maxsize 10000
using namespace std;
int main() {
	string str;
	cin >> str;
	stack<char> s,res;
	char ch;
	for (auto iter = str.begin(); iter != str.end(); iter++) {
		ch = *iter;
		if (ch != ')'&&ch != '<') {
			s.push(ch);
		}
		else if (ch == ')') {
			while (s.top() != '('&&!s.empty()) {
				s.pop();
			}
			if(!s.empty())
			s.pop();
		}
		else if (ch == '<'&&!s.empty()) {
			if(s.top()!='(')
			s.pop();
		}
	}
	while (!s.empty()) {
		ch = s.top();
		s.pop();
		res.push(ch);
	}
	while (!res.empty()) {
		ch = res.top();
		res.pop();
		cout << ch;
	}
	return 0;
}