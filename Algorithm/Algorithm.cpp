#include <iostream>
#include "BinaryTreeInorderTraversal.h"

int main()
{
	TreeNode* root = new TreeNode(1);
	TreeNode* right = new TreeNode(2);
	TreeNode* left = new TreeNode(3);
	root->right = right;
	right->left = left;
	vector<int> test = inorderTraversal(root);
	delete left;
	delete right;
	delete root;
	return 0;
}