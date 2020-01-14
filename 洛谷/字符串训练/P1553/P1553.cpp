#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string reverse2(string s) {
	/*将一段字符串翻转并去除前面的0*/
	reverse(s.begin(), s.end());
	int zerocount = 0;
	for (auto i : s) {
		if (i == '0')zerocount++;
		else break;
	}
	s.erase(s.begin(), s.begin() + zerocount);
	return (s != "" ? s:"0");
}

string ReverseTail(string s) {
	/*将一段字符串翻转并去掉末尾的0*/
	reverse(s.begin(), s.end());
	int zerocount = 0;
	for (auto iter = s.end() - 1; iter != s.begin(); iter--) {
		if (*iter == '0')zerocount++;
		else break;
	}
	s.erase(s.end() - zerocount, s.end());
	return (s != "" ? s : "0");
}


int main() {
	string s;
	cin >> s;
	if (s.back() == '%') {
		cout<<reverse2(s.substr(0,s.size()-1));
		return 0;
	}
	if (s.find('.')!=std::string::npos ) {
		int pos = s.find('.');
		string left = reverse2(s.substr(0, pos));
		string right = ReverseTail(s.substr(pos + 1));
		cout << left << "." << right;
		return 0;
	}

	if (s.find('/') != std::string::npos) {
		int pos = s.find('/');
		string left=reverse2(s.substr(0, pos));
		string right= ReverseTail(s.substr(pos + 1));
		cout << left << "/" << right;
		return 0;
	}

	cout << reverse2(s);
	return 0;
}