#include<iostream>
#include<string>
using namespace std;

int dp[1005];//����dp[i]Ϊ��s[i]��β����Ļ����Ӵ�����

string longestPalindrome(string s) {
	int len = s.size();
	string ans;
	for (int i = 0; i<len; i++) {
		dp[i] = 1;
	}
	int maxsize = 0;
	for (int i = 1; i<len; i++) {
		if (s[i] == s[i - dp[i - 1]]) {
			dp[i] = dp[i - 1] + 1;
		}
		if (i - dp[i - 1] - 1 >= 0 && s[i] == s[i - dp[i - 1] - 1]) {
			dp[i] = dp[i - 1] + 2;
		}
		if (dp[i]>maxsize) {
			ans = s.substr(i - dp[i] + 1, dp[i]);
			maxsize = dp[i];
		}
	}
	return ans;
}

int main() {
	string s1 = "bananas";
	cout << longestPalindrome(s1);

	return 0;
}