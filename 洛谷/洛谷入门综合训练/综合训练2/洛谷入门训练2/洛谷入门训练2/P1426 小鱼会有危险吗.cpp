#include<iostream>
using namespace std;
int main() {
	float s, x;
	cin >> s >> x;
	float l = s - x;
	float r = s + x;
	float percent = 0.98;
	float firststep = 7;
	float sum = 0;
	while (1) {
		if (sum > r) {
			cout << "n";
			break;
		}
		else if (sum >= l&&sum < r) {
			float ldist = sum - l;
			float rdist = r - sum;
			float ltime = ldist / firststep;
			float rtime = rdist / (firststep*percent);
			float sumtime = ltime + rtime;
			if (sumtime >= 1)cout << "y";
			else cout << "n";
			break;
		}
		else {
			sum += firststep;
			firststep = firststep*percent;
		}
	}
	return 0;
}