#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

// ����0��ǰ����д,�ڱ��ı���û��
// ����1��ʹ��ǡ�ñ�����3ά���
// ����2��ʹ��ѹ��ά�ȵ�2ά���

int dp[205][205];//����dp[j][k]Ϊ����Դ1С��ǡ��Ϊj����Դ2����ǡ��Ϊkʱ��ķ����еļ�ֵ���ֵ
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

	memset(dp, -1, sizeof(dp));
	dp[0][0] = 0;

	for (int i = 1; i <= n; i++) {
		for (int m = M; m >= 0; m--) {
			for (int t = T; t >= 0; t--) {
				if (m >= list[i].money&&t >= list[i].time&&dp[m - list[i].money][t - list[i].time] != -1) {
					dp[m][t] = max(dp[m][t], dp[m - list[i].money][t - list[i].time] + 1);
				}
			}
		}
	}
	int res = 0;
	for (int m = 0; m <= M; m++) {//��n�����������
		for (int t = 0; t <= T; t++) {
			res = max(res, dp[m][t]);
		}
	}
	cout << res;

	return 0;
}


// ��άʹ��ǡ�ñ����ķ�������

//int dp[105][205][205];//����dp[i][j][k]Ϊ������ǰi����Ʒ����Դ1С��ǡ��Ϊj����Դ2����ǡ��Ϊkʱ��ķ����еļ�ֵ���ֵ
//struct obj {
//	int money;
//	int time;
//}list[105];

//int main() {
//	int n, M, T;
//	cin >> n >> M >> T;
//	for (int i = 1; i <= n; i++) {
//		cin >> list[i].money >> list[i].time;
//	}
//
//	memset(dp, -1, sizeof(dp));
//	for (int i = 0; i <= n; i++) {
//		dp[i][0][0] = 0;
//	}
//
//	for (int i = 1; i <= n; i++) {
//		for (int m = 1; m <= M; m++) {
//			for (int t = 1; t <= T; t++) {
//				if (m >= list[i].money&&t >= list[i].time&&dp[i - 1][m - list[i].money][t - list[i].time]!=-1) {//��ǰ������Ч�Ҳ�Խ��
//					dp[i][m][t] = max(dp[i - 1][m][t], dp[i - 1][m - list[i].money][t - list[i].time] + 1);
//				}
//				else if(dp[i - 1][m][t] != -1){//��һ��������Ч������i��Խ����,����̳�
//					dp[i][m][t] = dp[i - 1][m][t];
//				}
//			}
//		}
//	}
//	int res = 0;
//	for (int m = 0; m <= M; m++) {//��n�����������
//		for (int t = 0; t <= T; t++) {
//			res = max(res, dp[n][m][t]);
//		}
//	}
//	cout << res;
//
//	return 0;
//}