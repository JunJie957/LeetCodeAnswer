
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// ����1���ݹ�
class Solution {
public:
    vector<int> ans;
    void dfs(TreeNode* root) {
        if (root == nullptr) return;
        dfs(root->left);
        ans.emplace_back(root->val);
        dfs(root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        dfs(root);
        return ans;
    }
};

// ����2������
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        if (root != nullptr) s.emplace(root);
        while (!s.empty()) {
            TreeNode* t = s.top(); s.pop();
            ans.emplace_back(t->val);
            if (t->right != nullptr) s.emplace(t->right);
            if (t->left != nullptr) s.emplace(t->left);
        }
        return ans;
    }
};

// ����3��Morris����
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) return res;
        TreeNode* p1 = root, * p2 = nullptr;
        while (p1 != nullptr) {
            p2 = p1->left;
            if (p2 != nullptr) {
                while (p2->right != nullptr && p2->right != p1) {
                    p2 = p2->right;
                }
                if (p2->right == nullptr) {
                    res.emplace_back(p1->val);
                    p2->right = p1;
                    p1 = p1->left;
                    continue;
                } else {
                    p2->right = nullptr;
                }
            } else {
                res.emplace_back(p1->val);
            }
            p1 = p1->right;
        }
        return res;
    }
};
