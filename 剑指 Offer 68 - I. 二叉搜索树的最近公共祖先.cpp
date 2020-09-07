/*
	利用二叉搜索树的有序性，直接判断当前遍历应当向左走还是向右走，还是直接返回
*/

// 1.递归
class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root->val < p->val && root->val < q->val)
			return lowestCommonAncestor(root->right, p, q);
		if (root->val > p->val && root->val > q->val)
			return lowestCommonAncestor(root->left, p, q);
		return root;
	}
};

// 2.迭代
class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		while (root) {
			if (root->val < p->val && root->val < q->val) root = root->right;
			else if (root->val > p->val && root->val > q->val) root = root->left;
			else return root;
		}
		return root;
	}
};
