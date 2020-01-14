#include <iostream>
#define MaxTree 10
#define ElementType char
#define Tree int
#define Null -1
struct TreeNode {
	ElementType element;
	Tree left;
	Tree right;
}T1[MaxTree], T2[MaxTree];

int BuildTree(TreeNode T[]) {
	int N;
	scanf("%d\n", &N);
	int i = 0;
	char data, r, l;
	int check[MaxTree];
	for (int i = 0; i < N; i++) check[i] = 0;

	if (N > 0) {
		for (int i = 0; i < N; i++) {
			scanf("%c %c %c\n", &data, &r, &l);
			T[i].element = data;
			if (r != '-') {
				T[i].right = r - '0';
				check[T[i].right] = 1;
			}
			else {
				check[T[i].right] = -1;
			}
			if (l != '-') {
				T[i].left = l - '0';
				check[T[i].left] = 1;
			}
			else {
				check[T[i].right] = -1;
			}
		}
	}

	for ( i = 0; i < N; i++) {
		if (!check[i]) break;
	}
	int res = i;
	return res;
}

int IsSame(Tree R1, Tree R2) {
	if (R1 == Null&&R2 == Null) return 1;
	if ((R1 == Null&&R2 != Null) || (R1 != Null&&R2 == Null)) return 0;
	if (T1[R1].element != T2[R2].element) return 0;
	//if (T1[R1].left == Null&&T2[R2].left == Null) return IsSame(T1[R1].right, T2[R2].right);
	return (IsSame(T1[R1].right, T2[R2].right) && IsSame(T1[R1].left, T2[R2].left)) || (IsSame(T1[R1].right, T2[R2].left) && IsSame(T1[R1].left, T2[R2].right));
}

int main() {
	Tree R1, R2;
	R1 = BuildTree(T1);
	R2 = BuildTree(T2);
	int res = IsSame(R1, R2);
	if (res)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}