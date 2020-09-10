/*
    方法1：递归
    时间复杂度：O(n)
    空间复杂度：最坏情况下需要空间O(n)，平均情况为O(logn)
*/
class Solution {
public:
    vector<int> res;
    void inorder(TreeNode* root) {
        if (root == nullptr) return;
        inorder(root->left);
        res.emplace_back(root->val);
        inorder(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return res;
    }
};

/*
    方法2：颜色标记法(太强了) 
    执行用时：0 ms, 在所有 C++ 提交中击败了 100.00% 的用户
    内存消耗：7.1 MB, 在所有 C++ 提交中击败了 69.83% 的用户
*/
class Solution {
    vector<int> res;
public:
    vector<int> inorderTraversal(TreeNode* root) {
        bool white = false, gray = true;
        stack<pair<bool, TreeNode*>> s;
        s.push(make_pair(white, root));
        while (!s.empty()) {
            bool color = s.top().first;
            TreeNode* t = s.top().second;
            s.pop();
            if (t == nullptr) continue;
            if (color == white) {
                s.push(make_pair(white, t->right));
                s.push(make_pair(gray, t));
                s.push(make_pair(white, t->left));
            }
            else {
                res.emplace_back(t->val);
            }
        }
        return res;
    }
};
