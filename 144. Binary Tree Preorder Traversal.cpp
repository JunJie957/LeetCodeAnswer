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
	vector<int> preorderTraversal(TreeNode* root) 
	{
        if(root == nullptr)
            return res;
            
		dfs(root);
		return res;
	}

	void dfs(TreeNode* root)
	{
		res.push_back(root->val);

		if (root->left != nullptr)
			dfs(root->left);

		if (root->right != nullptr)
			dfs(root->right);
	}

private:
	vector<int> res;

};