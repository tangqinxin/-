//#include<iostream>
//#include<algorithm>
//using namespace std;
//int n, k;
//int cnt = 0;
//
//void dfs(int last,int sum,int cur) {
//	if (cur == k) {//cur==k�͵���ͷ�ˣ�ֱ���ж�sum��֪���Ƿ����
//		if (sum == n) {
//			cnt++;
//		}
//		return;
//	}
//	//if (last*(k-cur)+sum>n) {
//	//	return;//��֦�����֮��Ķ�ȡ��Сֵ���Ǳ�n����ô������
//	//}
//	for (int i = last; i*(k-cur)+sum <= n; i++) {//���͵�����Լ�֦����ֹ����ظ����Ҫ����ö�٣�i��last��ʼö�ٱ�֤����
//		dfs(i, sum + i, cur + 1);
//	}
//}
//
//int main() {
//	cin >> n >> k;
//	dfs(1, 0, 0);
//	cout << cnt;
//	return 0;
//}


#include<iostream>
using namespace std;
int n, k;//������n�ֳ�k�� 
int f[205][10];//f[i][j]Ϊ��i��Ϊj�����ķַ� 
int main()
{
	cin >> n >> k;
	f[0][0] = 1;//��ʼ�� 
	for (int t = 1; t <= n; t++)//�ֳ���������Ĵ�С 
		for (int i = t; i <= n; i++)//����һ��Ĵ�С 
			for (int j = 1; j <= k; j++)//�ֵĶ��� 
				f[i][j] += f[i - t][j - 1];
	cout << f[n][k];//���������n�ֳ�k�ݵķַ� 
	return 0;
}