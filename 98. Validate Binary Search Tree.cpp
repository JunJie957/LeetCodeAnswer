#include <string>
#include <vector>
#include <stack>
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
    void inorder(vector<int>& nums, TreeNode* root) {
        if (!root) {
            return;
        }
        inorder(nums, root->left);
        nums.emplace_back(root->val);
        inorder(nums, root->right);
    }
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        vector<int> nums;
        inorder(nums, root);
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] <= nums[i - 1]) {
                return false;
            }
        }
        return true;
    }
};