#include<iostream>
#include<cstring>
#include<math.h>
using namespace std;
#define maxsize 20000
int Prime[maxsize+1];

bool IsPrime(int x) {
	bool flag = 1;
	for (int i = 2; i <=sqrt(x); i++) {
		if (x%i == 0) {
			flag = 0;
			break;
		}
	}
	return flag;
}

int main() {
	memset(Prime, 0, maxsize * sizeof(int));
	Prime[2] = 1;
	int n;
	cin >> n;
	for(int i=3;i<n;i++){
		if (IsPrime(i)) { 
			Prime[i] = 1; 
		}
	}//´ò±í
	bool FlagFind = 0;
	for (int i = 2; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (Prime[i] == 1 && Prime[j] == 1 && n - i - j >= 0 && Prime[n - i - j] == 1) {
				cout << i << " " << j << " " << n - i - j << endl;
				FlagFind = 1;
					break;
			}
		}
		if (FlagFind == 1)break;
	}

	return 0;
}