/*
    ����1���ݹ�
    ʱ�临�Ӷȣ�O(n)
    �ռ临�Ӷȣ���������Ҫ�ռ�O(n)��ƽ�����ΪO(logn)
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
    ����2����ɫ��Ƿ�
    ִ����ʱ��0 ms, ������ C++ �ύ�л�����100.00%���û�
    �ڴ����ģ�8.5 MB, ������ C++ �ύ�л�����52.63%���û�
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
    ����3����ͨջ
    ʱ�临�Ӷȣ�O(n)
	�ռ临�Ӷȣ�O(n) 
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
