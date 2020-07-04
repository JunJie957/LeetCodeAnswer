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
    bool check(TreeNode* u, TreeNode* v)
    {
        // 使用队列来进行迭代操作
        queue <TreeNode*> q;
        q.push(u); q.push(v);

        while (!q.empty()) 
        {
            u = q.front(); q.pop();
            v = q.front(); q.pop();

            if (!u && !v) continue;

            if ((!u || !v) || (u->val != v->val)) return false;

            // 对称：左 = 右
            q.push(u->left);
            q.push(v->right);

            // 对称： 右 = 左
            q.push(u->right);
            q.push(v->left);
        }
        return true;
    }

    bool isSymmetric(TreeNode* root) 
    {
        return check(root, root);
    }
};