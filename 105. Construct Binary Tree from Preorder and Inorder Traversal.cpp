#include <string>
#include <vector>
#include <stack>
#include <queue>
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
private:
    unordered_map<int, int> index;
public:
    TreeNode* build(const vector<int>& preorder, int preL, int preR, int inL, int inR) {
        if (preL > preR) return nullptr;

        TreeNode* root = new TreeNode(preorder[preL]);
        int loc = index[preorder[preL]];
        int dis = loc -inL;

        root->left = build(preorder, preL + 1, preL + dis, inL, loc - 1);
        root->right = build(preorder,preL + dis+1, preR,loc + 1, inR);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size = preorder.size();
        for (int i = 0; i < size; ++i) {
            index[inorder[i]] = i;
        }
        return build(preorder, 0, size - 1, 0, size - 1);
    }
};
