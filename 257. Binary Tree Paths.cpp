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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (root == nullptr) return res;

        queue<TreeNode*> q;      // 遍历需要的节点队列
        queue<string> ss;       //  使用字符串队列来维护之前的遍历状态，遍历到叶节点后，进行回溯
        q.push(root);
        ss.push(to_string(root->val));

        string s = "";
        TreeNode* node = nullptr;
        while (!q.empty())
        {
            node = q.front(); q.pop();
            s = ss.front();   ss.pop();

            if (node->left == nullptr && node->right == nullptr)
                res.push_back(s);

            if (node->left != nullptr)
            {
                ss.push(s + "->" + to_string(node->left->val));
                q.push(node->left);
            }

            if (node->right != nullptr)
            {
                ss.push(s + "->" + to_string(node->right->val));
                q.push(node->right);
            }
        }
        return res;
    }
};