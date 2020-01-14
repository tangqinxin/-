#include<iostream>
#include<cstdio>
#include<map>
#pragma warning(disable:4996)
using namespace std;
#define maxsize 1005

int T[maxsize];
int maxteam, maxscore;
int main() {
	int n;
	cin >> n;
	int team, member, score;
	map<int, int>mp;//记录组号和第几组
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d-%d %d", &team, &member, &score);
		T[team] += score;
		if (mp.find(team) == mp.end()) {
			mp[team]++;
		}
	}

	for (auto iter = mp.begin(); iter != mp.end(); iter++) {
		int index = iter->first;
		if (T[index] > maxscore) {
			maxteam = index;
			maxscore = T[index];
		}
	}

	cout << maxteam <<" " <<maxscore;
	return 0;
}