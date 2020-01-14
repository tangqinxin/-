#include<iostream>
#define maxsize 100
using namespace std;
int tree[maxsize];
int root[maxsize][maxsize];
int maxsum[maxsize][maxsize];
int n;

int dfs(int l, int r) {
	//���[l,r]�����ڵ�����
	if (l == r) {
		root[l][r] = l;
		return tree[l];
	}
	if (l > r) {
		return 1;
	}
	if (maxsum[l][r]) {
		//˼����Ϊʲô�������ʹ�ü��仯������Ϊʲô��ȥ�������ֵ���ѵ����ֵ����������
		//���������������ö�٣�ÿһ��ö������ͬ�����ڵļ����������ȫһ���ģ��������ͬ�����ڲ����ڸ��£������ȫ����ʹ�ü��仯������
		return maxsum[l][r];
	}

	for (int i = l; i <= r; i++) {
		int temp = dfs(l, i - 1)*dfs(i + 1, r) + tree[i];
		if (temp > maxsum[l][r]) {
			maxsum[l][r] = temp;
			root[l][r] = i;
		}
	}
	return maxsum[l][r];
}

void TreeTransver(int l,int r) {
	//ǰ������������������ڵ�
	if (l > r)return;
	cout << root[l][r] << " ";
	TreeTransver(l, root[l][r] - 1);
	TreeTransver(root[l][r]+1,r);
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> tree[i];
	}

	cout<<dfs(1, n)<<endl;
	TreeTransver(1, n);
	return 0;
}