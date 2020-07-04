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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        // 层序遍历：采用队列记录每一层的所有节点值，
        // 通过for()循环记录了每一层的所有子节点
        // 然后采用栈记录每一层的所有value值

        queue<TreeNode*> q; 
        vector<vector<int>> v;
        vector<int> tmp;

        if(root != nullptr)
        {
             q.push(root);
             tmp.push_back(root->val);
             v.push_back(tmp);
             tmp.clear();
        }
           
        while(!q.empty())
        { 
            for(int i = q.size() - 1; i >= 0; --i)
            {
                if(q.front()->left != nullptr)
                {
                    q.push(q.front()->left);
                    tmp.push_back(q.front()->left->val);
                }
            
                if(q.front()->right != nullptr)
                {
                    q.push(q.front()->right);
                    tmp.push_back(q.front()->right->val);
                }

                q.pop();
            }

            if(!tmp.empty())
            {
                v.push_back(tmp);
                tmp.clear();
            }
        }   

        return v;
    }
};