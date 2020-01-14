#include<iostream>
#define maxsize 10000
using namespace std;
typedef struct TreeNode* Tree;
struct TreeNode {
	int val;
	Tree left;
	Tree right;
	TreeNode(int x) :val(x),left(NULL),right(NULL){}
};


Tree InsertBST(Tree T,int x) {
	if (T == NULL) {
		T = new TreeNode(x);
	}
	else {
		if (T->val>x) {
			T->left = InsertBST(T->left, x);
		}
		else if (T->val < x) {
			T->right = InsertBST(T->right, x);
		}
	}
	return T;
}

int Sum(TreeNode* T) {
	if (T == NULL)return 0;
	int lsum, rsum, sum;
	sum = 0;
	lsum = Sum(T->left);
	rsum = Sum(T->right);
	sum = lsum + rsum + T->val;
	return sum;
}

int main() {
	int N;
	cin >> N;
	int a[maxsize];
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	Tree T=NULL;
	for (int i = 0; i < N; i++) {
		T = InsertBST(T, a[i]);
	}
	cout << Sum(T,0);

	return 0;
}