/*
	方法1 ： 栈
	时间复杂度：O(n)
	空间复杂度：O(n) 
*/  
class Solution {
    vector<int> res;
public:
    vector<int> preorder(Node* root) {
        if (root == nullptr) return {};
        stack<Node*> s;
        s.push(root);
        while (!s.empty()) {
            Node* t = s.top();
            s.pop();
            res.push_back(t->val);
            for (int i = t->children.size() - 1; i >= 0; --i) {
                s.push(t->children[i]);	// 从右往左压入栈中 
            }
        }
        return res;
    }
};

/*
	方法2：递归 
*/
class Solution {
    vector<int> res;
public:
    void pre(Node* root) {
        if (root == nullptr) return;
        res.push_back(root->val);
        for (int i = 0; i < root->children.size(); ++i) {
            pre(root->children[i]);
        }
    }
    vector<int> preorder(Node* root) {
        pre(root);
        return res;
    }
};
