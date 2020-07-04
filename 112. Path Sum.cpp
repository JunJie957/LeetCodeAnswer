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
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == nullptr) return false;
        
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, root->val));

        int cur_sum = 0;
        TreeNode* cur_node = nullptr;
        while (!q.empty())
        {
            auto front = q.front();
            q.pop();

            cur_node = front.first;
            cur_sum = front.second;
            if(cur_node->left == nullptr && cur_node->right == nullptr && cur_sum == sum)
                return true;
                
            if (cur_node->left != nullptr)
                q.push(make_pair(cur_node->left, cur_sum + cur_node->left->val));

            if (cur_node->right != nullptr)
                q.push(make_pair(cur_node->right, cur_sum + cur_node->right->val));
        }
        return false;
    }
};