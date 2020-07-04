class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        int len = nums.size();
        for (int i = 0; i < len; ++i)
        {
            if (m.find(target - nums[i]) != m.end())
                return { m[target - nums[i]], i };

            m[nums[i]] = i;
        }
        return {};
    }
};