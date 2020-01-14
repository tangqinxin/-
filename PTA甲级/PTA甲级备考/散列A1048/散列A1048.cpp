#include<iostream>
#include<climits>
using namespace std;
#define maxsize 100005
int hashtable[maxsize];
int ans1, ans2;

int main() {
	int n, m;
	ans1 = INT_MAX;
	ans2 = INT_MAX;

	int flag = false;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		hashtable[num]++;
		if (hashtable[m - num]>=1) {
			if (num == m - num&&hashtable[num] == 1)continue;//防止有2个相同的数
			flag = true;
			int tmp1 = num;
			int tmp2 = m - num;
			int minval = tmp1 < tmp2 ? tmp1 : tmp2;
			if (minval < ans1) {
				ans1 = minval;
				ans2 = m - ans1;
			}
		}
	}
	if (flag == true) {
		cout << ans1 << " " << ans2;
	}
	else {
		cout << "No Solution";
	}
	return 0;
}