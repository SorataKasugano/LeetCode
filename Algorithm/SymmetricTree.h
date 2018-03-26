#pragma once
/*
101. Symmetric Tree
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3

But the following [1,2,2,null,3,null,3] is not:

  1
 / \
2   2
 \   \
 3    3

Note:
Bonus points if you could solve it both recursively and iteratively. */

#define NULL 0
#include <stack>
#include <utility>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 1.iterative
bool isSymmetric(TreeNode* root) {
	stack<pair<TreeNode*, TreeNode*>> params;
	params.push(make_pair(root, root));
	TreeNode *l, *r;
	while (!params.empty())
	{
		l = params.top().first;
		r = params.top().second;
		params.pop();
		if (!(l || r)) continue;
		else if (!(l&&r)) return false;
		else if (l->val != r->val) return false;
		params.push(make_pair(l->left, r->right));
		params.push(make_pair(l->right, r->left));
	}
	return true;
}

// 2.recursive
//bool isSymmetric(TreeNode* root) {
//	return isMirror(root, root);
//}
//bool isMirror(TreeNode* l, TreeNode* r)
//{
//	return !(l&&r) ? !l && !r : l->val == r->val && isMirror(l->left, r->right) && isMirror(l->right, r->left);
//}