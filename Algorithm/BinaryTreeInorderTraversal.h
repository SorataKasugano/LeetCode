#pragma once
/*
94. Binary Tree Inorder Traversal
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree [1,null,2,3],

   1
	\
	 2
	/
   3

return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively? */

#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> inorderTraversal(TreeNode* root) {
	// 1.recursive
	//if (!root) return vector<int>();
	//vector<int> ret, right;
	//if (root->left) ret = inorderTraversal(root->left);
	//ret.push_back(root->val);
	//if (root->right)
	//{
	//	right = inorderTraversal(root->right);
	//	ret.insert(ret.end(), right.begin(), right.end());
	//}
	//return ret;

	// 2.iterative
	vector<int> ret;
	TreeNode *node=root,*aux;
	while (node)
	{
		if (!node->left)
		{
			ret.push_back(node->val);
			node = node->right;
		}
		else
		{
			aux = node->left;
			while (aux->right && (aux->right != node)) 
				aux = aux->right;
			if (!aux->right)
			{
				aux->right = node;
				node = node->left;
			}
			else
			{
				aux->right = nullptr;// necessary if the BT construct should be retain
				ret.push_back(node->val);
				node = node->right;
			}
		}
	}
	return ret;
}