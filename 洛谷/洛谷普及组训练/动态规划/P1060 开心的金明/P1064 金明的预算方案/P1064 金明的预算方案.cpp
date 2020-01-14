#include<iostream>
#include<algorithm>
#include<cstring>
#include<set>
#include<string>
#include<vector>
using namespace std;

struct obj {
	int v;
	int p;
	int q;
};

int main() {
	obj list[61];
	int N, m;
	cin >> N >> m;
	int cnt[61] = {};//ͳ��ÿһ��ļ�������
	int groups = 0;//ͳ���ж�����
	obj GroupDivision[61][61];//����һ�����������
	
	for (int i = 1; i <= m; i++) {
		cin >> list[i].v >> list[i].p >> list[i].q;
		groups = max(groups, list[i].q);
		if (list[i].q) {//����Ǹ���
			cnt[list[i].q]++;//��Ӧ����ĸ�����������
			GroupDivision[list[i].q][cnt[list[i].q]].v = list[i].v;//�����Ϣ
			GroupDivision[list[i].q][cnt[list[i].q]].p = list[i].p;
			GroupDivision[list[i].q][cnt[list[i].q]].q = list[i].q;
		}
	}

	/*˼·��ÿһ���ڣ����е�ѡ�񷽰��ǻ���ģ�ÿһ�ַ������Կ����Ƿ��鱳���ڵ�һ����Ʒ��
	��������ڲ���n1����Ʒ����ô����ÿ����Ʒ����ѡ���Բ�ѡ������2^n1�ַ�������������ѡ��ѡ����2^n1+1�ַ���*/
	//��ÿһ�����ڵı�����һ��01�滮
	//int dp[32001];
	int dp[201];
	int cnt2[61] = {};
	int V[61][11] = {};
	int P[61][11] = {};
	for (int i = 1; i <= m; i++) {
		if (!list[i].q) {//���������
			memset(dp, -1, sizeof(dp));
			dp[0] = 0;
			for (int k = 1; k <= cnt[i]; k++) {
				for (int j = N - list[i].v; j >= 0; j--) {
					if (j >= GroupDivision[i][k].v&&dp[j - GroupDivision[i][k].v] != -1)
						dp[j] = max(dp[j], dp[j - GroupDivision[i][k].v] + GroupDivision[i][k].v*GroupDivision[i][k].p);
				}
			}
			//01����������֮�󣬵õ���dp[j]�ĺ����ǣ����ڵ�i�����Ʒ��ǡ�û���jԪ�ĸ�����Ǯ���ܹ��õ����������棻ÿһ��j��Ӧһ�������������ų�
			//���������������֮�󣬻���Ҫ�����������Ч�ķ������м�¼�������¼Ӧ���������ڲ��Ž��м�¼
			for (int j = 0; j <= N - list[i].v; j++) {
				if (dp[j] != -1) {
					cnt2[i]++;
					V[i][cnt2[i]] = j + list[i].v;
					P[i][cnt2[i]] = dp[j] + list[i].v*list[i].p;
				}
			}
		}
		//��������ж��Ҿ��ú�j==0���ж����ظ��ˣ���ʵ���Բ�д
		if (!list[i].q) {
			cnt2[i]++;
			V[i][cnt2[i]] = list[i].v;
			P[i][cnt2[i]] = list[i].v*list[i].p;
		}
	}
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= m; i++) {
		for (int j = N; j >= 0; j--) {
			for (int k = 1; k <= cnt2[i]; k++) {
				if (j >= V[i][k])
					dp[j] = max(dp[j], dp[j - V[i][k]] + P[i][k]);
			}
		}
	}
	int res = 0;
	for (int j = 0; j <= N; j++) {
		res = max(res, dp[j]);
	}
	cout << res;

	return 0;
}