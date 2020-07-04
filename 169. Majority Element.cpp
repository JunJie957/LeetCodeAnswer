class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int size = nums.size();
        unordered_map<int, int> m;
        for (int i = 0; i < size; ++i)
        {
            auto iter = m.find(nums[i]);
            if (iter == m.end())
                m.insert(make_pair(nums[i], 1));
            else
            {
                ++iter->second;
                if (iter->second > size / 2)
                    return nums[i];
            }
        }
        return nums[0];
    }
};