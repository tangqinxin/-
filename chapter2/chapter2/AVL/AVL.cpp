#include<iostream>
typedef struct treenode * Tree;
struct treenode {
	int val;
	Tree left;
	Tree right;
	treenode(int val):val(val),left(NULL),right(NULL){}
};

Tree FindMin(Tree T);
/*搜索树树插入部分*/
Tree insert(Tree T,int val) {
	if (T == NULL) {
		T = new treenode(val);
		return T;
	}
	else if (T->val > val) {
		T->left = insert(T->left, val);
	}
	else if (T->val < val) {
		T->right = insert(T->right, val);
	}
	/*如果val已经存在，那么什么都不做*/
	return T;
}

/*返回某个节点的树的高度*/
int gethight(Tree T) {
	int LH, RH, MaxH;
	if (T == NULL) return 0;
	else {
		LH = gethight(T->left);
		RH = gethight(T->right);
		MaxH = LH > RH ?  LH : RH;
		return (MaxH + 1);
	}
}
/*删除某个节点*/
Tree DeleteTreeNode(Tree T,int val) {
	Tree temp = T;
	if (T == NULL) return NULL;
	else {
		if (T->val > val) {
			T->left = DeleteTreeNode(T->left, val);
		}
		else if (T->val < val) {
			T->right = DeleteTreeNode(T->right, val);
		}
		else {/*当前节点的值就是val，此时根据左右子树分开讨论*/
			if (T->left == NULL) {/*只有右子树或者无左右子树*/
				T = T->right;
				delete temp;
			}
			else if (T->right == NULL) {/*只有左子树*/
				T = T->left;
				delete temp;
			}
			else {/*左右子树都有*/
				temp = FindMin(T->right);
				T->val = temp->val;
				T->right = DeleteTreeNode(T->right, temp->val);
			}
		}
	}
	return T;
}

/*查找最小值的节点*/
Tree FindMin(Tree T) {
	if (T == NULL) return NULL;
	else if (T->left == NULL) return T;
	else if (T->left != NULL) {
		return FindMin(T->left);
	}
}



Tree LLrotation(Tree T) {
	Tree B = T->left;
	T->left = B->right;
	B->right = T;
	return B;
}

Tree RRrotation(Tree T) {
	Tree B = T->right;
	T->right = B->left;
	B->left = T;
	return B;
}

Tree LRrotation(Tree T) {
	T->left = RRrotation(T->left);
	return LLrotation(T);
}

Tree RLrotation(Tree T) {
	T->right = LLrotation(T->right);
	return RRrotation(T);
}

/*生成AVL*/
Tree AVLinsert(Tree T, int x) {
	if (T == NULL) {
		T = new treenode(x);
	}
	else {/*插入非空树，按照搜索树插入，结合一些旋转*/
		if (T->val > x) {
			T->left = AVLinsert(T->left, x);
			/*插完之后要判断*/
			if (gethight(T->left) - gethight(T->right) == 2) {
				if (T->left->val > x)
					T = LLrotation(T);
				else
					T = LRrotation(T);
			}
		}
		else if (T->val < x) {
			T->right = AVLinsert(T->right, x);
			if (gethight(T->left) - gethight(T->right) ==-2) {
				if (T->right->val < x)
					T = RRrotation(T);
				else
					T = RLrotation(T);
			}
		}
	}
	return T;
}

int main() {
	using namespace std;
	int N,num;
	Tree T=NULL;
	cin >> N;
	while (N--) {
		cin >> num;
		T=AVLinsert(T, num);
	}
	cout << T->val;
	return 0;
}