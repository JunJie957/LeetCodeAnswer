// 哈希表 
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> um; // key - 数组值 value - 下标
		for (int i = 0; i < nums.size(); ++i) {
			auto iter = um.find(target - nums[i]);
			if (iter != um.end()) {
				return { iter->second, i };
			}
			um[nums[i]] = i;
		}
		return {};
	}
};
