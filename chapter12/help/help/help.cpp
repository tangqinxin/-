#include<iostream>
#include<map>
using namespace std;
int main() {
	char ch;
	map<char, int> set;
	int isfirst = 1;
	int count = 0;
	while (cin >> ch) {
		auto iter = set.find(ch);//查找ch元素
		if (iter == set.end()) {//不存在该元素
			int count = 1;
			set.insert(make_pair(ch, count));
		}
		else {
			iter->second++;//已经有该元素了
		}

		int flag = 1;//是否可以输出
		for (iter = set.begin(); iter != set.end(); iter++) {
			if (iter->second == 1) {//存在单一元素，还不能输出
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