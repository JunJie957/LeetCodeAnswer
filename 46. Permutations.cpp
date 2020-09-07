class Solution {
public:
	int len;
	vector<vector<int>> res;

	// 回溯法：对于每一个数字，在每一个位置的摆放有两种选择：放 或 不放
	void backtrack(vector<int>& nums, int loc) {
		if (loc == len) {
			res.emplace_back(nums);
			return;
		}

		for (int i = loc; i < len; ++i) {
			swap(nums[i], nums[loc]);	// 选第 loc 个数
			backtrack(nums, loc + 1);
			swap(nums[i], nums[loc]);	// 不选第 loc 个数
		}
	}

	vector<vector<int>> permute(vector<int>& nums) {
		len = nums.size();
		backtrack(nums, 0);
		return res;
	}
};
