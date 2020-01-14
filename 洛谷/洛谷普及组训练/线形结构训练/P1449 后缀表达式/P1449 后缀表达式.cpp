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
		else if (ch == '.') {//������
			s.push(num);
			num = 0;//num����
		}
		else{
			num2 = s.top();//����ȳ�����������Ǻ��������
			s.pop();//Ĭ�ϱ��ʽ����������pop֮ǰ��Ҫ�鿴�Ƿ�Ϊ��
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