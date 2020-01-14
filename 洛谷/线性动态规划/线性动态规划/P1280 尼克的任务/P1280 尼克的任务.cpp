#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

struct event{
	int start;
	int last;
};

int main() {
	int n, k;
	cin >> n >> k;
	event s[10005];//��ȡ��Ϣ
	int cnt[10005];//���ڼ�¼�¼�������
	memset(cnt, 0, sizeof(cnt));
	for (int i = 1; i <= k; i++) {
		cin >> s[i].start >> s[i].last;
		cnt[s[i].start]++;
	}
	int dp[10005];//����dp[i]Ϊ�ӵ�iʱ�̵�nʱ�̵Ŀռ�ʱ������ֵ
	memset(dp, 0, sizeof(dp));
	dp[n + 1] = 0;//��ʼ������û�п���ʱ��
	for (int i = n; i >= 1; i--) {
		if (cnt[i] == 0) {
			dp[i] = dp[i + 1] + 1;//iʱ��û��Ҫ��ʼ�����񣬿ռ�ʱ���i+1ʱ�̻��1���飬��ľ��ǵ�i����
		}
		else if (cnt[i] != 0) {//��i���ӱ����п�ʼ������,�Ǿ���һ����õ�����
			for (int j = 1; j <=k; j++) {
				if (s[j].start == i) {//��������k�������дӵ�i���ӿ�ʼ�ķ���
					dp[i] = max(dp[i], dp[i + s[j].last]);
				}
			}
		}
	}
	cout << dp[1];

	return 0;
}