#include<iostream>
#define maxsize 100
using namespace std;
int tree[maxsize];
int root[maxsize][maxsize];
int maxsum[maxsize][maxsize];
int n;

int dfs(int l, int r) {
	//求出[l,r]区间内的最大和
	if (l == r) {
		root[l][r] = l;
		return tree[l];
	}
	if (l > r) {
		return 1;
	}
	if (maxsum[l][r]) {
		//思考：为什么这里可以使用记忆化搜索？为什么不去更新这个值，难道这个值就是最大的吗？
		//这里的搜索类似于枚举，每一次枚举在相同区间内的计算过程是完全一样的，因此在相同区间内不存在更新，因此完全可以使用记忆化搜索。
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
	//前序遍历输出，先输出根节点
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