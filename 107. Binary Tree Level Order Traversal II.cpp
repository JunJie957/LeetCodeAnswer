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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        // 层序遍历：采用队列实现
        queue<vector<TreeNode*>> q;

        // 存储根节点，作为单独的一层
        vector<TreeNode*> cur_level;
        if (root != nullptr)cur_level.push_back(root);
        if (!cur_level.empty()) q.push(cur_level);

        vector<int> value;              // 存储当前层上所有节点的val
        vector<TreeNode*> next_level;   // 存储下一层的所有节点
        vector<vector<int>> res;        // 存储整个树的节点值
        while (!q.empty())
        {
            // 获取本层所有的节点
            cur_level = q.front();
            q.pop();

            // 存储本层所有节点的值
            value.clear();
            for (const auto& iter : cur_level)
            {
                value.push_back(iter->val);
            }
            if (!value.empty()) res.push_back(value);

            // 存储下一层的所有节点
            next_level.clear();
            for (const auto& iter : cur_level)
            {
                if (iter->left != nullptr) next_level.push_back(iter->left);
                if (iter->right != nullptr) next_level.push_back(iter->right);
            }
            if(!next_level.empty()) q.push(next_level);
        }
        reverse(res.begin(), res.end()); // 逆转整个数组
        return res;
    }
};