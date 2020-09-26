/*
    ����1���ݹ�
    ʱ�临�Ӷȣ�O(n)
    �ռ临�Ӷȣ���������Ҫ�ռ�O(n)��ƽ�����ΪO(logn)
*/
class Solution {
public:
    vector<int> res;
    void inorder(TreeNode* root) {
        if (root == nullptr) return;
        inorder(root->left);
        res.emplace_back(root->val);
        inorder(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return res;
    }
};

/*
    ����2����ɫ��Ƿ�(̫ǿ��) 
    ִ����ʱ��0 ms, ������ C++ �ύ�л����� 100.00% ���û�
    �ڴ����ģ�7.1 MB, ������ C++ �ύ�л����� 69.83% ���û�
*/
class Solution {
    vector<int> res;
public:
    vector<int> inorderTraversal(TreeNode* root) {
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
                s.push(make_pair(gray, t));
                s.push(make_pair(white, t->left));
            }
            else {
                res.emplace_back(t->val);
            }
        }
        return res;
    }
};
