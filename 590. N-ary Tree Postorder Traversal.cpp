// 方法1：栈 
class Solution {
    vector<int> res;
public:
    vector<int> postorder(Node* root) {
        if (root == nullptr) return {};
        stack<Node*> s;
        s.push(root);
        while (!s.empty()) {
            Node* t = s.top();
            s.pop();
            res.push_back(t->val);
            for (int i = 0; i < t->children.size(); ++i) {
                s.push(t->children[i]);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

// 方法2：递归 
class Solution {
    vector<int> res;
public:
    void post(Node* root) {
        if (root == nullptr) return;
        for (int i = 0; i < root->children.size(); ++i) {
            post(root->children[i]);
        }
        res.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        post(root);
        return res;
    }
};
