class Solution {
public:
	int len;
	vector<vector<int>> res;

	// ���ݷ�������ÿһ�����֣���ÿһ��λ�õİڷ�������ѡ�񣺷� �� ����
	void backtrack(vector<int>& nums, int loc) {
		if (loc == len) {
			res.emplace_back(nums);
			return;
		}

		for (int i = loc; i < len; ++i) {
			swap(nums[i], nums[loc]);	// ѡ�� loc ����
			backtrack(nums, loc + 1);
			swap(nums[i], nums[loc]);	// ��ѡ�� loc ����
		}
	}

	vector<vector<int>> permute(vector<int>& nums) {
		len = nums.size();
		backtrack(nums, 0);
		return res;
	}
};
