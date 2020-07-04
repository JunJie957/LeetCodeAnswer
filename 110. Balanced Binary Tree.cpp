class Solution {
public:
    
    bool helper(TreeNode* root, int& hight)
    {
        if (root == nullptr)
        {
            hight = -1;
            return true;
        }

        int left, right;

        // 自底向上计算高度
        if (helper(root->left, left) && helper(root->right, right) && abs(left - right) < 2)
        {
            hight = max(left, right) + 1;
            return true;
        }
        else
            return false;
    }

    bool isBalanced(TreeNode* root) {
        int hight;
        return helper(root, hight);
    }
};