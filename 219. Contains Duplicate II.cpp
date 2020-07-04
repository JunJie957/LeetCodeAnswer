class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
       unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i)
        {
            auto iter = m.find(nums[i]);
            if (iter != m.end())
            {
                if (abs(iter->second - i) <= k)
                    return true;
                else
                    iter->second = i;
            }
            else
            {
                m.insert(make_pair(nums[i], i));
            }
        }
        return false;
    }
};