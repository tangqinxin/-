#include <stdio.h>
#include <cstring>
#define Tree int
#define MaxTree 10
#define ElementType char
#define NULL -1

struct TreeNode {
	ElementType data;
	Tree left;
	Tree right;
}T1[MaxTree], T2[MaxTree];


int main() {
	Tree R1, R2;
	R1 = BuildTree(T1);
	R2 = BuildTree(T2);
	if (Isomorphic(R1, R2)) printf("Yes\n");
	else printf("No\n");

	return 0;
}

Tree BuildTree(struct TreeNode T[]) {
	int N;
	ElementType cl, cr;
	int check[MaxTree];
	int root;
	scanf("%d\n", &N);
	if (N) {
		for (int i = 0; i < N; i++) check[i] = 0;
		for (int i = 0; i < N; i++) {
			scanf("%c %c %c\n", &T[i].data, &cl, &cr);
			if (cl != '-') {
				T[i].left = cl - '0';
				check[T[i].left] = 1;
			}
			else T[i].left = NULL;
			if (cr != '-') {
				T[i].right = cr - '0';
				check[T[i].right] = 1;
			}
			else T[i].right= NULL;
		}
		int i;
		for ( i = 0; i < N; i++) if (!check[i]) break;
		root = i;
	}
	return root;
}

int Isomorphic(Tree R1, Tree R2) {
	if ((R1 == NULL) && (R2 == NULL))//都为空
		return 1;
	if ((R1 == NULL) && (R2 != NULL) || (R1 != NULL) && (R2 == NULL))//其中一个为空
		return 0;
	if (T1[R1].data != T2[R2].data)//根节点不同
		return 0;
	if ((T1[R1].left == NULL) && (T2[R2].left == NULL))//都没有左子树
		return Isomorphic(T1[R1].right, T2[R2].right);
	if (((T1[R1].left != NULL) && (T2[R2].left != NULL) && (T1[T1[R1].left].data) == (T2[T2[R2].left].data)))
	return (Isomorphic(T1[R1].left, T2[R2].left) && Isomorphic(T1[R1].right, T2[R2].right));
	else
		return(Isomorphic(T1[R1].left, T2[R2].right) && Isomorphic(T1[R1].right, T2[R2].left));
}