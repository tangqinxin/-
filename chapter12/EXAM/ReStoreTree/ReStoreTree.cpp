#include<iostream>
#define Maxsize 50
using namespace std;
typedef char ElementType;
typedef char str[Maxsize];
typedef struct TreeNode* Tree;
struct TreeNode {
	ElementType Data;
	Tree left;
	Tree right;
	TreeNode() :left(NULL), right(NULL){}
};

Tree ReBuildTree(str s1, str s2,int l1,int r1,int l2,int r2) {
	if (l1 == r1) {
		Tree T = new TreeNode;
		T->Data = s1[l1];
		T->left = NULL;
		T->right = NULL;
		return T;
	}
	Tree T = new TreeNode;
	T->Data = s1[l1];
	char ch = s1[l1];
	int pos;
	for (pos = l2;pos <=r1 &&s2[pos] != ch; pos++) {}
	int num = pos - l2+1;//l2到pos有多少个数
	T->left = ReBuildTree(s1, s2, l1+1,l1+num-1,l2,pos-1);
	T->right = ReBuildTree(s1, s2, l1+num,r1,pos+1,r2);

	return T;
}

int MaxHight(Tree T) {
	if (T == NULL)return 0;
	int LH, RH, res;
	LH = MaxHight(T->left);
	RH = MaxHight(T->right);
	res = (LH > RH ? LH : RH) + 1;
	return res;
}

int main() {
	int N;
	cin >> N;
	str s1, s2;
	cin >> s1 >> s2;
	Tree T;
	T=ReBuildTree(s1, s2,0, N-1,0,N-1);
	cout << MaxHight(T);

	return 0;
}