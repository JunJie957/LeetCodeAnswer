// bfs 
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) return res;
        
        vector<TreeNode*> node{ root };
        vector<int> layer{ root->val };
        res.push_back(layer);
        queue<vector<TreeNode*>> q;
        q.push(node);

        while (!q.empty()) {
            vector<TreeNode*> cur = q.front();
            q.pop();
            
            node.clear();
            layer.clear();
            for (auto i : cur) {
                if (i->left != nullptr) {
                    node.push_back(i->left);
                    layer.push_back(i->left->val);
                }
                if (i->right != nullptr) {
                    node.push_back(i->right);
                    layer.push_back(i->right->val);
                }
            }
            if (!node.empty()) {
                q.push(node);
                res.push_back(layer);
            }
        }
        return res;
    }
};

// dfs 
class Solution {
public:
    vector<vector<int>> res;
    void level(TreeNode* root, int layer) {
        if (root == nullptr) return;
        if (layer >= res.size()) res.emplace_back(vector<int>{});
        res[layer].emplace_back(root->val);
        level(root->left,  layer + 1);  // 将下一层的相同广度的节点入队
        level(root->right, layer + 1);  // 将下一层的相同广度的节点入队
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        level(root, 0);
        return res;
    }
};
