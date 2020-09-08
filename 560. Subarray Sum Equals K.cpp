/*
	方法1：枚举法

		(1) 枚举当前遍历的数组中是否存在和为k的连续子数组
		(2) 不断遍历获得新长度的数组，并在新数组中寻找符合条件的连续子数组
		(3) 时间复杂度O(n*n),因为存在两个for循环
		(4) 空间复杂度O(1)，只需要常量存储 数组和 以及 统计次数
*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
		int count = 0;
		for (int start = 0; start < nums.size(); ++start) {
			int sum = 0;
			for (int end = start; end >= 0; --end) {
				sum += nums[end];
				if (sum == k) {
					++count;
				}
			}
		}
		return count;
    }
};

/*
	方法2：前缀和 + 哈希表优化 
*/ 
class Solution {
public:
	int subarraySum(vector<int>& nums, int k) {
		unordered_map<int, int> mp;
		mp[0] = 1;
		int count = 0, pre = 0;
		for (auto& x : nums) {
			pre += x;
			if (mp.find(pre - k) != mp.end()) 
				count += mp[pre - k];
			mp[pre]++;
		}
		return count;
	}
};
