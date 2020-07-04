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
    int maxDepth(TreeNode* root) 
    {
        int ans = 0;
		queue<TreeNode*> q;

		if (root != nullptr)
			q.push(root);

		while (!q.empty())
		{
            // 每次将当前层的所有节点入队，然后层数+1，
            // 统计完所有层，即得到最大的深度
			for (int i = q.size() - 1; i >= 0; --i)
			{
				if (q.front()->right != nullptr)
					q.push(q.front()->right);

				if (q.front()->left != nullptr)
					q.push(q.front()->left);

				q.pop();
			}
			++ans;
		}
		return ans;
    }
};