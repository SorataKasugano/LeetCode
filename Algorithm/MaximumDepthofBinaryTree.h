#pragma once
/*
104. Maximum Depth of Binary Tree
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

For example:
Given binary tree [3,9,20,null,null,15,7],

  3
 / \
9  20
  /  \
 15   7

return its depth = 3.*/

#include <stddef.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

int maxDepth(TreeNode* root) {
	if (!root) return 0;
	int leftDepth = maxDepth(root->left) + 1;
	int rightDepth = maxDepth(root->right) + 1;
	return leftDepth>rightDepth ? leftDepth : rightDepth;
}