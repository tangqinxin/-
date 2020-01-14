#include<iostream>
#include<string>
using namespace std;
bool IsHui(string s) {
	if (s.size() == 0)return true;

	int i = 0;
	int j = s.size()-1;
	bool res = true;
	while (i <= j) {
		if (s[i] != s[j]) {
			res = false;
			break;
		}
		else {
			i++;
			j--;
		}
	}
	return res;
}

string longestPalindrome(string s) {
	int maxsize = 0;
	string res;
	for (int i = 0; i<s.size(); i++) {
		for (int j = i; j<s.size(); j++) {
			string temp = s.substr(i, j - i + 1);
			if (IsHui(temp) && temp.size()>maxsize) {
				res = temp;
				maxsize = temp.size();
			}
		}
	}
	return res;
}

string longestPalindrome2(string s) {
	int maxsize = 0;
	string res;
	for (int i = 1; i <= s.size();i++) {
		for (int j = 0; j + i <= s.size(); j++) {
			string temp = s.substr(j, i);//���±�j��ʼ��ȡ����Ϊi���Ӵ�
			if (IsHui(temp)) {
				res = temp;
				maxsize = temp.size();
				break;//��ǰ���Ѿ�û��ѭ���ı�Ҫ�ˣ�ȥ���������Ĵ�
			}
		}
	}
	return res;
}


int main() {
	string s = "azwdzwmwcqzgcobeeiphemqbjtxzwkhiqpbrprocbppbxrnsxnwgikiaqutwpftbiinlnpyqstkiqzbggcsdzzjbrkfmhgtnbujzszxsycmvipjtktpebaafycngqasbbhxaeawwmkjcziybxowkaibqnndcjbsoehtamhspnidjylyisiaewmypfyiqtwlmejkpzlieolfdjnxntonnzfgcqlcfpoxcwqctalwrgwhvqvtrpwemxhirpgizjffqgntsmvzldpjfijdncexbwtxnmbnoykxshkqbounzrewkpqjxocvaufnhunsmsazgibxedtopnccriwcfzeomsrrangufkjfzipkmwfbmkarnyyrgdsooosgqlkzvorrrsaveuoxjeajvbdpgxlcrtqomliphnlehgrzgwujogxteyulphhuhwyoyvcxqatfkboahfqhjgujcaapoyqtsdqfwnijlkknuralezqmcryvkankszmzpgqutojoyzsnyfwsyeqqzrlhzbc";
	cout<<longestPalindrome2(s);

	return 0;
}