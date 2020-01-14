#include<iostream>
#include<iterator>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;
int main() {
	string text;
	cin >> text;
	stack<string::iterator> s;
	string::iterator temp;
	for (auto iter = text.begin(); iter != text.end(); ) {
		if (*iter == '(') {
			s.push(iter);
			text.erase(iter);
		}
		else if (*iter == ')') {
			temp = s.top();
			s.pop();
			reverse(temp, iter);
			text.erase(iter);
		}
		else iter++;
	}
	cout << text;
	return 0;
}