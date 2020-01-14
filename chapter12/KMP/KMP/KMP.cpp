#include<iostream>
#include<cstring>
#define Maxsize 1000001
#define PMax 100001
typedef char pattern[PMax];
typedef int MatchArr[PMax];
using namespace std;
/*简单版本的建立match数组*/
int* BuildMatch(pattern pat) {
	int len = strlen(pat);
	int* Match = new int[len];
	Match[0] = -1;
	int i, j;
	for ( j = 1; j < len;j++) {
		for (i = 0; i < j; i++) {
			if (pat[i] != pat[j - i]) {
				Match[j] = i-1;//1个匹配记为0
				break;
			}
		}
	}
	return Match;
}
/*更好的版本*/
int* BuildMatch2(pattern pat) {
	int i, j;
	int patlen = strlen(pat);
	int* Match = new int[patlen];
	Match[0] = -1;
	for (j = 1; j < patlen; j++) {
		i = Match[j - 1];
		while (i>=0&&pat[j]!=pat[i+1]) {
			i = Match[i];
		}
		if (pat[i + 1] == pat[j]) {
			Match[j] = i + 1;
		}
		else
			Match[j] = -1;
	}
}


int Judge(char* text, pattern pat) {
	int* Match=BuildMatch2(pat);
	int t, p;
	t = p = 0;
	int res = -1;
	int patlen = strlen(pat);
	int textlen = strlen(text);
	if (patlen > textlen)return -1;
	while (t <textlen) {
		if (text[t] == pat[p]) {
			p++;
			t++;
		}
		else {
			if (p>0)
				p = Match[p - 1] + 1;
			else if (p == 0) {
				t++;
			}
		}
		if (p == patlen) {
			res = t-patlen;
			break;
		}
	}
	return res;
}


int main() {
	char* Text = new char[Maxsize];
	pattern Pat;
	int N,res;
	cin >> Text;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> Pat;
		res=Judge(Text, Pat);
		if (res == -1) {
			cout << "Not Found\n";
		}
		else {
			printf("%s\n", Text + res);
		}
	}
	delete[]Text;
	return 0;
}