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
    int minDepth(TreeNode* root) {
         if (root == nullptr) return 0;  
        
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 1));

        int curDepth = 0;
        while (!q.empty())
        {
            auto front = q.front(); 
            q.pop();
            
            TreeNode* curNode = front.first;
            curDepth = front.second;

            if (curNode->left == nullptr && curNode->right == nullptr)
                break;

            if (curNode->left != nullptr)
                q.push(make_pair(curNode->left, curDepth + 1));

            if (curNode->right != nullptr)
                q.push(make_pair(curNode->right, curDepth + 1));
        }
        return curDepth;
    }
};