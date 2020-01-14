#include<iostream>
#include<stack>
using namespace std;


bool IsNum(char ch) {
	return ch >='0'&&ch <= '9';
}

int main() {
	stack<int> s;
	char ch;
	int num=0;
	int res;
	int num1, num2;
	while (cin >>ch &&ch != '@') {
		if (IsNum(ch)) {
			num = num * 10 + ch - '0';
		}
		else if (ch == '.') {//操作数
			s.push(num);
			num = 0;//num归零
		}
		else{
			num2 = s.top();//后进先出，最上面的是后面输入的
			s.pop();//默认表达式合理，正常在pop之前需要查看是否为空
			num1 = s.top();
			s.pop();
			if (ch == '+')res = num1 + num2;
			if (ch == '-')res = num1 - num2;
			if (ch == '*')res = num1 * num2;
			if (ch == '/')res = num1 / num2;
			s.push(res);
		}
	}
	res = s.top();
	cout << res;
	return 0;
}