#include<iostream>
#include<algorithm>
#include<list>
#include<iterator>
using namespace std;

int main() {
	int N;
	cin >> N;
	list<int> l = { 1 };
	int k, p;
	list<int>::iterator pos[100005];
	bool Erase[100005] = {};
	pos[1] = l.begin();
	for (int i = 2; i <= N; i++) {
		cin >> k >> p;
		//auto iter = find(l.begin(), l.end(), k);//找到k这个值的迭代器;但是这个线性查找太慢了，我们用一个打表的方法来优化
		if (p == 0) {//左边插入
			pos[i]=l.insert(pos[k], i);
		}
		else {//右边插入
			//advance(iter, 1);
		    pos[i]=l.insert(next(pos[k]), i);//next是iterator里面的方法
		}
	}
	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> k;
		if (Erase[k] == false) {
			l.erase(pos[k]);
			Erase[k] = true;
		}
	}
	//for (int i = 0; i < M; i++) {
	//	cin >> k;
	//	auto iter=find(l.begin(), l.end(), k);
	//	if(iter!=l.end())
	//	l.erase(iter);
	//}
	for (auto x : l) {
		cout << x << " ";
	}
	return 0;
}