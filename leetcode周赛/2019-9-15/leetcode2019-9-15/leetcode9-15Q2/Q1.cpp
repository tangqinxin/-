#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	int maxNumberOfBalloons(string text) {
		char word[] = "balloon";
		int bucket[5] = { 0,0,0,0,0 };
		for (int i = 0; i<text.size(); i++) {
			if (text[i] == 'b')bucket[0]++;
			else if (text[i] == 'a')bucket[1]++;
			else if (text[i] == 'l')bucket[2]++;
			else if (text[i] == 'o')bucket[3]++;
			else if (text[i] == 'n')bucket[4]++;
		}
		int count = 0;
		while (bucket[0] >= 1 && bucket[1] >= 1 && bucket[2] >= 2 && bucket[3] >= 2 && bucket[4] >= 1) {
			count++;
			bucket[0]--;
			bucket[1]--;
			bucket[2] = bucket[2] - 2;
			bucket[3] = bucket[3] - 2;
			bucket[4]--;
		}
		return count;
	}
};