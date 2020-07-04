class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int len = nums.size();
        if(len == 0) return 0;

       
        unique(nums.begin(), nums.end());

        int count = 0;
        for (int i = 0; i < len - 1; ++i)
        {
            if (nums[i] < nums[i + 1])  ++count;
            else break;
        }
        return count + 1;
    }
};