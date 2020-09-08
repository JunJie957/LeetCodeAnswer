// ��ϣ�� 
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> um; // key - ����ֵ value - �±�
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
