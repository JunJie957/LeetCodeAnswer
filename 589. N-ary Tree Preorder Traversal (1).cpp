/*
	����1 �� ջ
	ʱ�临�Ӷȣ�O(n)
	�ռ临�Ӷȣ�O(n) 
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
                s.push(t->children[i]);	// ��������ѹ��ջ�� 
            }
        }
        return res;
    }
};

/*
	����2���ݹ� 
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
