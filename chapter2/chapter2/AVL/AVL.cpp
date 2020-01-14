#include<iostream>
typedef struct treenode * Tree;
struct treenode {
	int val;
	Tree left;
	Tree right;
	treenode(int val):val(val),left(NULL),right(NULL){}
};

Tree FindMin(Tree T);
/*�����������벿��*/
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
	/*���val�Ѿ����ڣ���ôʲô������*/
	return T;
}

/*����ĳ���ڵ�����ĸ߶�*/
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
/*ɾ��ĳ���ڵ�*/
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
		else {/*��ǰ�ڵ��ֵ����val����ʱ�������������ֿ�����*/
			if (T->left == NULL) {/*ֻ����������������������*/
				T = T->right;
				delete temp;
			}
			else if (T->right == NULL) {/*ֻ��������*/
				T = T->left;
				delete temp;
			}
			else {/*������������*/
				temp = FindMin(T->right);
				T->val = temp->val;
				T->right = DeleteTreeNode(T->right, temp->val);
			}
		}
	}
	return T;
}

/*������Сֵ�Ľڵ�*/
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

/*����AVL*/
Tree AVLinsert(Tree T, int x) {
	if (T == NULL) {
		T = new treenode(x);
	}
	else {/*����ǿ������������������룬���һЩ��ת*/
		if (T->val > x) {
			T->left = AVLinsert(T->left, x);
			/*����֮��Ҫ�ж�*/
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