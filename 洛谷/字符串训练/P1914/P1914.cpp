#include<iostream>
#include<string>
#include<cstring>
using namespace std;
/*
int main() {
	int n;
	char input[51];
	cin >> n;
	cin >> input;
	int N = 'z' - 'a' + 1;
	n = n%N;
	int len = strlen(input);
	for (int i = 0; i < len; i++) {
		if (input[i]+n>'z')input[i] =input[i]+n- 'z'+'a'-1;
		else input[i]+=n;
	}
	cout << input;
	return 0;
}
*/
int main() {
	char p[] = "goodLuck";
	p[4] = 'l';
	cout << p;
	return 0;
}