class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if (root == nullptr) return res;

        queue<vector<Node*>> q;
        vector<Node*> next{ root };			// 每层的所有节点 
        vector<int> layer{ root->val };		// 每次的所有节点值 
        q.push(next);
        res.emplace_back(layer);
        while (!q.empty()) {
            vector<Node*> vc = q.front(); q.pop();
            layer.clear(); next.clear();
            for (int i = 0; i < vc.size(); ++i) {
                for (int j = 0; j < vc[i]->children.size(); ++j) {
                    if (vc[i]->children[j] != nullptr) {
                        layer.emplace_back(vc[i]->children[j]->val);
                        next.emplace_back(vc[i]->children[j]);
                    }
                }
            }
            if (!layer.empty()){
                res.emplace_back(layer);
                q.push(next);
            }
        }
        return res;
    }
};
