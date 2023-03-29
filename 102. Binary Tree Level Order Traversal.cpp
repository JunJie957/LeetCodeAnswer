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
    void levelOrder(vector<vector<int>>& ans, TreeNode* root, const int layer) {
        if (!root) return;
        if (layer >= ans.size()) {
            ans.emplace_back(vector<int>{root->val});
        } else {
            ans[layer].emplace_back(root->val);
        }
        levelOrder(ans, root->left, layer + 1);
        levelOrder(ans, root->right, layer + 1);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        levelOrder(ans, root, 0);
        return ans;
    }
};

// bfs
class Solution2 {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;

        // layer
        vector<int> layer{ root->val };
        res.emplace_back(layer);
        // node
        vector<TreeNode*> node { root };
        queue<vector<TreeNode*>> q;
        q.push(node);

        while (!q.empty()) {
            auto cur = q.front();
            q.pop();

            node.clear();
            layer.clear();

            for (auto& i : cur) {
                if (i->left) {
                    node.emplace_back(i->left);
                    layer.emplace_back(i->left->val);
                }
                if (i->right) {
                    node.emplace_back(i->right);
                    layer.emplace_back(i->right->val);
                }
            }

            if (!node.empty()) {
                q.push(node);
                res.emplace_back(layer);
            }
        }
        return res;
    }
};
