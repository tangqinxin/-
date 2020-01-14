#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;

int equalSubstring(string s, string t, int maxCost) {
	vector<int> cost;
	int temp;
	for (int i = 0; i<s.size(); i++) {
		temp = abs(s[i] - t[i]);
		cost.push_back(temp);//求出每个元素对应的花销
	}
	sort(cost.begin(), cost.end());
	int totalcost = 0;
	int count = 0;
	for (auto x : cost) {
		totalcost += x;
		if (totalcost>maxCost)
			break;
		count++;
	}
	return count;
}

int main() {
	string s = "krrgw";
	string t = "zjxss";
	int mc = 19;
	cout << equalSubstring(s, t, mc);
	return 0;
}