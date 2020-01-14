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
	//��֪s��s_wordƥ����k���ӿڣ���������Ҫ��s_wordƴ�ӵ�s��
	for (int i = k; i < s_word.size(); i++) {
		s += s_word[i];
	}
}

bool check(string nowstring, string s, int k) {
	//����ǰ�ַ���nowstring���ַ���s����ƥ�䣬����ƥ��k�����ȵĽӿ�
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
		if (used[i] >= 2)continue;//���ж��Ƿ�ʹ����2��
		//�ж��Ƿ��ܹ����кϲ�
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