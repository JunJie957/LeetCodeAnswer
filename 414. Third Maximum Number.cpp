class Solution {
public:
	int thirdMax(vector<int>& nums) {
		long int size = nums.size(), max_num = -3e10, second_num = -3e10, third_num = -3e10;
		if (size < 3) return *max_element(nums.begin(), nums.end());
		for (int i = 0; i < size; ++i) {
			if (nums[i] > max_num) {
				third_num = second_num;
				second_num = max_num;
				max_num = nums[i];
			} else if (nums[i] < max_num && nums[i] > second_num) {
				third_num = second_num;
				second_num = nums[i];
			} else if (nums[i] < second_num && nums[i] > third_num) {
				third_num = nums[i];
			}
		}
		if(third_num != -3e10) return third_num;
		return max_num;
	}
};
