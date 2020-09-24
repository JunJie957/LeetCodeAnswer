class Solution
{
private:
	TreeNode* pre;
	vector<int> ret;
	int max_count, cur_count, ret_count;

	void inOrder(TreeNode* root) {
		if (root == nullptr) return;
		inOrder(root->left);

		if (pre && pre->val == root->val) {
			cur_count++;	
		} else {
			cur_count = 1;	
		}

		if (cur_count > max_count) {
			max_count = cur_count;
			ret_count = 1;
		} else if (cur_count == max_count) {
			if (!ret.empty()) {	
				ret[ret_count] = root->val;
			}
			ret_count++;
		}
		pre = root;
		inOrder(root->right);
	}

public:
	vector<int> findMode(TreeNode* root) {
		pre = nullptr;
		max_count = 0, cur_count = 0, ret_count = 0;
		inOrder(root);	// 第一次中序遍历
		
		pre = nullptr;
		ret.resize(ret_count);
		cur_count = 0, ret_count = 0;
		inOrder(root);	// 第二次中序遍历
		return ret;
	}
};
