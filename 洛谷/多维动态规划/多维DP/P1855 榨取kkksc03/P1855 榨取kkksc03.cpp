#include<iostream>
#include<climits>
#include<algorithm>
#include<cstring>
using namespace std;

int dp[105][205][205];//��ǡ�ñ���
					  //����dp[i][j][k]Ϊ������ǰi����Ʒ����Դ1С��С�ڵ���j����Դ2����С�ڵ���kʱ��ķ����еļ�ֵ���ֵ
struct obj {
	int money;
	int time;
}list[105];

int main() {
	int n, M, T;
	cin >> n >> M >> T;
	for (int i = 1; i <= n; i++) {
		cin >> list[i].money >> list[i].time;
	}

	for (int i = 0; i <= n; i++) {
		dp[i][0][0] = 0;
	}

	for (int i = 1; i <= n; i++) {
		for (int m = 1; m <= M; m++) {
			for (int t = 1; t <= T; t++) {
				if (m >= list[i].money&&t >= list[i].time) {
					dp[i][m][t] = max(dp[i - 1][m][t], dp[i - 1][m - list[i].money][t - list[i].time] + 1);
				}
				else {
					dp[i][m][t] = dp[i - 1][m][t];//���������ôд����ʹmoney����time��ĳ��ά���ϳ����ˣ�����Ӧ�ü̳�i-1�Ľ������Ҫ
				}
			}
		}
	}

	cout<<dp[n][M][T];//ʹ�÷�ǡ�ñ�������Ҫ�����������

	return 0;
}