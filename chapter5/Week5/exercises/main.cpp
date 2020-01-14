#include <iostream>
#include <stack>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



bool hasPathSum(TreeNode* root, int sum) {
	stack<TreeNode*> s;
	TreeNode* temp = root;
	while (!s.empty() || temp != NULL) {
		while (temp != NULL) {
			s.push(temp);
			sum = sum - temp->val;
			temp = temp->left;
			if (sum == 0) return true;
		}
		temp = s.top();
		s.pop();
		sum = sum + temp->val;
		temp = temp->right;
	}
	return false;
}

int main() {
	TreeNode* t5=new TreeNode(5);
	TreeNode* t4 = new TreeNode(4);
	TreeNode* t8 = new TreeNode(8);
	TreeNode* t11 = new TreeNode(11);
	TreeNode* t13 = new TreeNode(13);
	TreeNode* t44 = new TreeNode(4);
	TreeNode* t7 = new TreeNode(7);
	TreeNode* t2 = new TreeNode(2);
	TreeNode* t1 = new TreeNode(1);
	t5->left = t4;
	t5->right = t8;
	t4->left = t11;
	t11->left = t7;
	t11->right = t2;
	t8->left = t13;
	t8->right = t44;
	t44->right = t1;
	bool res=hasPathSum(t5, 22);
	cout << res;

	return 0;
}