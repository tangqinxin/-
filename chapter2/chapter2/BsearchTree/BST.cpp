#include <iostream>
#include <stdio.h>
#include <malloc.h>
typedef Treenode* Tree;
struct Treenode {
	int val;
	Tree left;
	Tree right;
	int flag;
	Treenode(int val):val(val),left(NULL),right(NULL),flag(0){}
};

/*建立搜索树*/
Treenode* BuildTree(int N) {
	if (N <= 0) return NULL;
	int i, v;
	scanf("%d", &v);
	Tree T = new Treenode(v);
	for (i = 1; i < N; i++) {
		scanf("%d", &v);
		T = insert(T, v);
	}
	return T;
}
/*插入，并返回根节点*/
Treenode* insert(Treenode* T, int v) {
	if (T == NULL) {
		T =(Tree) malloc(sizeof(struct Treenode));
		T->val = v;
		T->left = NULL;
		T->right = NULL;
		T->flag = 0;
	}
	else {
		if (v > T->val) {
			T->right=insert(T->right, v);
		}
		else if (v < T->val) {
			T->left = insert(T->left, v);
		}
		else {
			return NULL;
		}
	}
	return T;
}

/*判别函数:在树中进行搜索，如果每次搜索经过的结点在前面出现过，就一致
否则不一致*/
int check(Tree T, int v) {
	if (T->flag) {
		if (v < T->val) return check(T->left, v);
		else if (v > T->val) return check(T->right, v);
		else return 0;
	}
	else {
		if (v == T->val) {
			T->flag = 1;
			return 1;
		}
		else return 0;
	}
}

void ResetT(Tree T)/*清除T中各个结点的flag标记,这个其实就是树的遍历*/
{
	if (T != NULL) {
		T->flag = 0;
		if (T->left != NULL) ResetT(T->left);
		if (T->right != NULL) ResetT(T->right);
	}
}

void FreeTree(Tree T)/*释放T的空间,递归树的遍历*/
{
	if (T != NULL) {
		if (T->left) FreeTree(T->left);
		if (T->right)FreeTree(T->right);
		free(T);
	}
}
int Judge(Tree T, int N) {
	int i, v, flag = 0;/*1表示不一致，0表示一致*/
	scanf("%d", &v);
	if (v != T->v) flag = 1;
	else T->flag = 1;
	for (i = 1; i < N; i++) {
		scanf("%d", &v);
		if ((!flag) && (!check(T, v))) flag = 1;
	}
	if (flag) return 0;
	else return 1;
}

int main() {
	int N, L, i;
	Tree T;
	scanf("%d", &N);
	while (N) {
		scanf("%d", &L);
		T = BuildTree(N);
		for (i = 0; i < L; i++) {
			if (Judge(T, N))printf("Yes\n");
			else printf("No\n");
			ResetT(T);
		}
		FreeTree(T);
		scanf("%d", &N);
	}
	return 0;
}
