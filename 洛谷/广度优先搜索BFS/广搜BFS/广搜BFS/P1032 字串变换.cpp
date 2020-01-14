#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<ctime>
#define maxsize 10
using namespace std;

string origin[maxsize];
string translated[maxsize];
string strA;
string strB;
int n;
map<string, int> mp;//�������м��仯�����ļ�֦

struct node {
	string str;
	int step;
};

bool match(string str1, string str2, int pos) {
	//���Խ�str1�е���str2��ͬ�Ĳ��ֽ���ƥ�䣬ƥ��ɹ��򷵻�true
	if (str1.size() < pos+str2.size()) {
		return false;//���str1����ͱ�str2�̣���ô�϶��ǲ��е�
	}
	int i;
	for ( i = 0; pos+i < str1.size()&&i<str2.size(); i++) {
		if (str1[pos + i] != str2[i]) {
			break;
		}
	}

	if (i == str2.size()) {
		return true;
	}
	else {
		return false;
	}
}

string transfer(const string& ori,int i,int pos) {
	//���Խ�ori����Ĵ�pos��ʼ��part�����滻Ϊ��Ӧ�Ĵ����ɹ��򷵻ظý����ʧ���򷵻ؿմ�
	string res;
	if (match(ori,origin[i], pos)) {
		string part = origin[i];
		res = ori.substr(0, pos);//ǰ�벿��
		res += translated[i];//ƥ���Ĳ���
		res += ori.substr(pos + origin[i].size());
		//���������������ѭ���Ļ����ͻᳬʱ����֪��Ϊʲô
		//int i = 0;
		//for ( i = pos + origin[i].size(); i < ori.size(); i++) {
		//	res += ori[i];
		//}
	}
	else {
		res = "";
	}
	return res;
}

string transfer2(const string& ori, int j, int i) {
	string ans = "";
	if (i + origin[j].length() > ori.length())
		return ans;

	for (int k = 0; k < origin[j].length(); k++)
		if (ori[i + k] != origin[j][k])
			return ans;

	ans = ori.substr(0, i);
	ans += translated[j];
	ans += ori.substr(i + origin[j].length());
	return ans;
}

string transfer3(const string& ori, int i, int pos) {
	string res = "";
	if (pos + origin[i].size() > ori.size()) {
		return res;
	}

	for (int k = 0; pos + k < ori.size() && k < origin[i].size(); k++) {
		if (ori[pos + k] != origin[i][k]) {
			return res;
		}
	}

	res = ori.substr(0, pos);
	res += translated[i];
	res += ori.substr(pos + origin[i].size());
	return res;
}

int bfs() {
	int res = 0;
	node s;
	s.str = strA;
	s.step = 0;
	queue<node> q;
	q.push(s);

	while (!q.empty()) {
		node tmp = q.front();
		q.pop();
		int len = tmp.str.size();

		if (tmp.step > 10) {
			res = tmp.step;
			break;
		}

		if (tmp.str == strB) {
			res = tmp.step;//�õ���������ֱ������
			break;
		}
		if (mp.count(tmp.str) == 1) {
			continue;//���仯�����ļ�֦
		}
		mp[tmp.str] = 1;//���м�¼

		for (int i = 0; i < n; i++) {//���ϳ��Խ��ֵ��еĴ����滻��ǰtmp.str�Ĵ�
			for (int j = 0; j < len; j++) {
				string strtmp;
				strtmp = transfer(tmp.str, i, j);
				if (strtmp == "")continue;
				node newstate;
				newstate.str = strtmp;
				newstate.step = tmp.step + 1;
				q.push(newstate);
			}
		}
	}

	return res;
}

int main() {
	cin >> strA >> strB;
	while (cin >> origin[n] >> translated[n]) {
		n++;
		if (n == 6)break;
	}

	int res = bfs();
	if (res > 10||res==0) {
		cout << "NO ANSWER!";
	}
	else {
		cout << res;
	}

	return 0;
}