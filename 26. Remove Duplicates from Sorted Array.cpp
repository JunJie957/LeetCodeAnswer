class Solution {
public:
	// ָ�뷨
	int removeDuplicates(vector<int>& nums) {
		if (nums.empty()) return 0;
		int not_equal_index = 0;
		for (int i = 1; i < nums.size(); ++i) {
			if (nums[i] != nums[not_equal_index]) {
				if (i > not_equal_index) {
					nums[not_equal_index + 1] = nums[i];
				}
				++not_equal_index;
			}
		}
		return not_equal_index + 1;
	}
};
