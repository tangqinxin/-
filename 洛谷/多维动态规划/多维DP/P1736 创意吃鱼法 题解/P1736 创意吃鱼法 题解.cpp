#include<iostream>
#include<algorithm>
using namespace std;

short mat[2505][2505];
short horizon[2505][2505];//h[i][j]Ϊ��[i,j]��ʼ������h[i][j]����λ��Ϊ0
short vertical[2505][2505];//v[i][j]Ϊ��[i,j]��ʼ������v[i][j]����λ��Ϊ0
short dp1[2505][2505];//����dp1[i][j]Ϊ����i,jΪ�����ξ������½�,�ĶԽ����ϵ����Ŀɳ�����,�������ξ�����˶Խ����ⲻ����������1
short dp2[2505][2505];//����dp1[i][j]Ϊ����i,jΪ�����ξ������½�,�ĶԽ����ϵ����Ŀɳ�����,�������ξ�����˶Խ����ⲻ����������1
short h2[2505][2505];//h2[i][j]Ϊ��[i,j]��ʼ������h2[i][j]����λ��Ϊ0
short v2[2505][2505];//v2[i][j]����Ϊ��[i,j]��ʼ������v2[i][j]����λ��Ϊ0�����ʺ�vertical[2505][2505]��ͬ


int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> mat[i][j];
		}
	}

	//����horizon
	//��ʼ��ˮƽ��һ�ж�Ϊ0
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (j == 1) {
				horizon[i][j] = 0;
			}
			else if (mat[i][j-1] == 0) {
				horizon[i][j] = horizon[i][j - 1] + 1;
			}
			else if (mat[i][j - 1] != 0) {
				horizon[i][j] = 0;
			}
		}
	}

	//����vertical
	//��ʼ��ˮƽ��һ�ж�Ϊ0
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i == 1) {
				vertical[i][j] = 0;
			}
			else if (mat[i-1][j] == 0) {
				vertical[i][j] = vertical[i-1][j] + 1;
			}
			else if (mat[i-1][j] != 0) {
				vertical[i][j] = 0;
			}
		}
	}

	//����dp1[i][j]
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (mat[i][j] == 0) {
				dp1[i][j] = 0;
			}
			else if (mat[i][j] != 0) {
				dp1[i][j] = min({ dp1[i - 1][j - 1],vertical[i][j],horizon[i][j] }) + 1;
			}
		}
	}

	//����h2[i][j]
	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= 1; j--) {
			if (j == m) {
				h2[i][j] = 0;
			}
			else if (mat[i][j + 1] == 0) {
				h2[i][j] = h2[i][j + 1] + 1;
			}
			else if (mat[i][j + 1] != 0) {
				h2[i][j] = 0;
			}
		}
	}

	//����v2[i][j]
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i == 1) {
				v2[i][j] = 0;
			}
			else if (mat[i - 1][j] == 0) {
				v2[i][j] = v2[i - 1][j] + 1;
			}
			else if (mat[i - 1][j] != 0) {
				v2[i][j] = 0;
			}
		}
	}

	//����dp2[i][j]
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (mat[i][j] == 0) {
				dp2[i][j] = 0;
			}
			else if (mat[i][j] != 0) {
				dp2[i][j] = min({ dp2[i - 1][j + 1],v2[i][j],h2[i][j] }) + 1;
			}
		}
	}

	short res1 = 0;
	short res2 = 0;
	short res = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			res1 = max(res1, dp1[i][j]);
			res2 = max(res2, dp2[i][j]);
			res = max(res1, res2);
		}
	}
	cout << res;

	return 0;
}