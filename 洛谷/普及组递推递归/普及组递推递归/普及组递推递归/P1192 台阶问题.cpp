#include<iostream>
#include<cstring>
using namespace std;
int n, k;
int ans;
#define MOD 100003
#define maxsize 100005
int mark[maxsize];//mark[i]��ʾ�ӵ�i������n���ж��ٷ���


//������
void dfs(int cur) {
	if (cur > n) {
		return;
	}
	if (cur == n) {
		ans++;
		return;
	}
	for (int i = 1; i <= k; i++) {
		dfs(cur + i);
	}
}

//�����,���仯
int dfs2(int cur) {
	//���ش�cur��n�ж����ַ���
	if (mark[cur] != -1) {
		return mark[cur];
	}
	if (cur > n) {
		return 0;
	}
	if (cur == n) {
		return 1;
	}
	//���û�м�¼����ô��Ҫ������
	int res=0;
	for (int i = 1; i <= k; i++) {
		if (cur + i <= n) {
			res += dfs2(cur + i);
		}
		if (cur + i > n)break;
	}
	mark[cur] = res%MOD;
	return mark[cur];
}

int main() {
	cin >> n >> k;
	//dfs(0);//������
	memset(mark, -1, sizeof(mark));
	mark[n] = 1;
	for (int i = n; i >= 0; i--) {
		dfs2(i);
	}
	ans = mark[0]%MOD;
	cout << ans;
	return 0;
}