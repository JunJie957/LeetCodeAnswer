#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSimilar(TreeNode* u, TreeNode* v) {
        queue<TreeNode*> que;
        que.emplace(u);
        que.emplace(v);
        while (!que.empty()) {
            u = que.front(); que.pop();
            v = que.front(); que.pop();
            if (!u && !v) continue;
            if ((!u || !v) || (u->val != v->val)) return false;
            que.emplace(u->left);
            que.emplace(v->right);
            que.emplace(u->right);
            que.emplace(v->left);
        }
        return true;
    }

    bool isSymmetric(TreeNode* root) {
        return isSimilar(root, root);
    }
};