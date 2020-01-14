#include<iostream>
#include<climits>
#include<vector>
using namespace std;
int coinChange(vector<int> &coins, int amount) {
	int* a = new int[amount + 1];
	a[0] = 0;
	for (int i = 1; i<amount + 1; i++) {
		a[i] = -1;
	}
	int money;
	int res;
	for (int i = 1; i<amount + 1; i++) {
		res = INT_MAX;
		for (int j = 0; j<coins.size(); j++) {
			money = coins[j];
			if (i - money >= 0 && a[i - money] != -1)
				res = res<(a[i - money] + 1) ? res : (a[i - money] + 1);
		}
		if (res==INT_MAX)
			a[i] = -1;
		else {
			a[i] = res;
		}
	}
	return a[amount];
}

int main() {
	vector<int> vec = { 1,2,5 };
	cout<<coinChange(vec, 11);

	return 0;
}