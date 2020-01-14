#include <iostream>
#include <stack>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


TreeNode* invertTree(TreeNode* root) {
	if (root == NULL) return NULL;
	else
		if (root->left == NULL&&root->right == NULL)
			return root;
		else {
			root->left = invertTree(root->right);
			root->right = invertTree(root->left);
		}
		return root;
}


int main() {
	TreeNode* t4 = new TreeNode(4);
	TreeNode* t2 = new TreeNode(2);
	TreeNode* t7 = new TreeNode(7);
	TreeNode* t1 = new TreeNode(1);
	TreeNode* t3 = new TreeNode(3);
	TreeNode* t6 = new TreeNode(6);
	TreeNode* t9 = new TreeNode(9);

	t4->left = t2;
	t4->right = t7;
	t2->left = t1;
	t2->right = t3;
	t7->left = t6;
	t7->right = t9;
	TreeNode* res=invertTree(t4);

	return 0;
}