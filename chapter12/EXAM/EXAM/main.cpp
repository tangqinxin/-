#include<iostream>
#include <string>
using namespace std;

int count(string s1, string s2, int N) {
	if (s1.size()==1)return 1;
	else {
		int res = 0;
		int Pos;
		string ls1, ls2,rs1,rs2;
		char ch = s1[0];
		Pos = s2.find(ch);
		ls1 = s1.substr(1, Pos );
		ls2 = s2.substr(0, Pos );
		rs1 = s1.substr(Pos + 1, N - Pos);
		rs2 = s2.substr(Pos + 1, N - Pos);
		int LH, RH;
		LH = count(ls1, ls2, Pos);
		RH = count(rs1, rs2, N - Pos);
		res= (RH > LH ?  RH : LH) + 1;
		return res;
	}
}


int main() {
	string pre, mid;
	int N;
	cin >> N;
	cin >> pre >> mid;
	cout<<count(pre, mid, N);

	return 0;
}