class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        // 哈希表
        int size = nums.size();

        unordered_set<int> s;
        for (auto i : nums)
            s.insert(i);

        for (int i = 0; i <= size; ++i)
        {
            if (s.find(i) == s.end())
                return i;
        }

        return -1;
    }
};