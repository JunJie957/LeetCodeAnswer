/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

	void dfs(TreeNode* root)
	{
		if (root == nullptr)
			return;

		if (root->left != nullptr)
			dfs(root->left);

		s.push_back(root);

		if (root->right != nullptr)
			dfs(root->right);
	}

	bool isValidBST(TreeNode* root) 
	{
		if (root == nullptr)
			return true;

		dfs(root);

		for (int i = 0; i < s.size() - 1; ++i)
		{
			if (s[i + 1]->val <= s[i]->val)
				return false;
		}
	
		return true;
	}

private:
	vector<TreeNode*> s;
};