/*
    方法1：递归
    时间复杂度：O(n)
    空间复杂度：最坏情况下需要空间O(n)，平均情况为O(logn)
*/
class Solution {
public:
    vector<int> res;
    void preorder(TreeNode* root) {
        if (root == nullptr) return;
        res.emplace_back(root->val);
        preorder(root->left);
        preorder(root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        preorder(root);
        return res;
    }
};

/*
    方法2：颜色标记法
    执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
    内存消耗：8.5 MB, 在所有 C++ 提交中击败了52.63%的用户
*/
class Solution {
    vector<int> res;
public:
    vector<int> preorderTraversal(TreeNode* root) {
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
                s.push(make_pair(white, t->left));
                s.push(make_pair(gray, t));
            }
            else {
                res.emplace_back(t->val);
            }
        }
        return res;
    }
};


/*
    方法3：普通栈
    时间复杂度：O(n)
	空间复杂度：O(n) 
*/
class Solution {
    vector<int> res;
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == nullptr) return {};
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode* t = s.top();
            s.pop();
            res.emplace_back(t->val);
            if (t->right) s.push(t->right);
            if (t->left)  s.push(t->left);
        }
        return res;
    }
};
