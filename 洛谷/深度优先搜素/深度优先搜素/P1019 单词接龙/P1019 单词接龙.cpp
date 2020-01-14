#include<iostream>
#include<string>
#include<algorithm>
#define maxsize 100
using namespace std;

string word[maxsize];
string Fischar;
int n;
int ans = 0;
int used[maxsize];

void add(string& s, string s_word, int k) {
	//已知s和s_word匹配了k个接口，接下来需要将s_word拼接到s上
	for (int i = k; i < s_word.size(); i++) {
		s += s_word[i];
	}
}

bool check(string nowstring, string s, int k) {
	//将当前字符串nowstring和字符串s进行匹配，仅仅匹配k个长度的接口
	bool res = true;
	int len = nowstring.size();
	if (len < k)return false;
	for (int j = 0; j < k; j++) {
		if (nowstring[len - k + j] != s[j]) {
			res = false;
			break;
		}
	}
	return res;
}

void DFS(string nowstring) {
	int curlen = nowstring.size();
	ans = max(ans, curlen);
	for (int i = 0; i < n; i++) {
		if (used[i] >= 2)continue;//先判断是否使用了2次
		//判断是否能够进行合并
		for (int j = 1; j <word[i].size(); j++) {
			if (check(nowstring,word[i],j)){
				string temp = nowstring;
				add(temp, word[i], j);
				if (temp == nowstring)continue;
				used[i]++;
				DFS(temp);
				used[i]--;
			}
		}
	}
}


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> word[i];
	}
	cin >> Fischar;
	DFS(Fischar);
	cout << ans << endl;

	return 0;
}