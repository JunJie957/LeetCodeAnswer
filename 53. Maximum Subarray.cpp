class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = nums[0],sum = 0;
        for (auto i : nums)
        {
            sum += i;
            if (max < sum) max = sum;
            if (sum < 0) sum = 0;
        }
        return max;
    }
};
