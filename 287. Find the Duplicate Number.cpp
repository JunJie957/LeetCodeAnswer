class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        unordered_set<int> s;
        int len = nums.size();
        for (int i = 0; i < len; ++i)
        {
            if (s.find(nums[i]) != s.end())
                return nums[i];
            s.insert(nums[i]);
        }
        return -1;
    }
};