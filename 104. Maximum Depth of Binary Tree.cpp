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
    int maxDepth(TreeNode* root) {
        if (!root) return 0;

        queue<TreeNode*> q;
        q.emplace(root);
        int ans = 0, layerNumber = q.size();
        while (!q.empty()) {
            while (layerNumber--) {
                if (q.front()->left) q.emplace(q.front()->left);
                if (q.front()->right) q.emplace(q.front()->right);
                q.pop();
            }
            ++ans;
            layerNumber = q.size();
        }
        return ans;
    }
};