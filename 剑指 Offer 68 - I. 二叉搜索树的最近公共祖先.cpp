/*
	���ö����������������ԣ�ֱ���жϵ�ǰ����Ӧ�������߻��������ߣ�����ֱ�ӷ���
*/

// 1.�ݹ�
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

// 2.����
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
