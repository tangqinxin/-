#include<iostream>
#include<map>
using namespace std;
int main() {
	char ch;
	map<char, int> set;
	int isfirst = 1;
	int count = 0;
	while (cin >> ch) {
		auto iter = set.find(ch);//����chԪ��
		if (iter == set.end()) {//�����ڸ�Ԫ��
			int count = 1;
			set.insert(make_pair(ch, count));
		}
		else {
			iter->second++;//�Ѿ��и�Ԫ����
		}

		int flag = 1;//�Ƿ�������
		for (iter = set.begin(); iter != set.end(); iter++) {
			if (iter->second == 1) {//���ڵ�һԪ�أ����������
				flag = 0;
			}
		}

		if (flag == 1) {
			for (iter = set.begin(); iter != set.end(); iter++) {
				count += iter->second;
			}
			if (isfirst == 1) {
				cout << count;
				isfirst = 0;
				set.clear();
				count = 0;
			}
			else {
				cout << "," << count;
				set.clear();
				count = 0;
			}
		}

	}
	return 0;
}