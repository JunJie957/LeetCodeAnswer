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
    void inOrder(vector<int>& nums, const TreeNode* root) {
        if (!root) return;
        inOrder(nums, root->left);
        nums.emplace_back(root->val);
        inOrder(nums, root->right);
    }
    bool IsOrder(const vector<int>& nums) {
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] <= nums[i - 1]) {
                return false;
            }
        }
        return true;
    }
    bool isValidBST(TreeNode* root) {
        vector<int> nums;
        inOrder(nums, root);
        return IsOrder(nums);
    }
};