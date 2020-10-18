class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return false;
        
        int maxNum = *max_element(nums.begin(), nums.end());
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int target = sum / 2;

        // ¼ôÖ¦
        if (sum % 2 == 1 || maxNum > target)  return false;

        // ¶¯Ì¬¹æ»®
        vector<int> dp(target + 1, 0);
        dp[0] = true;
        int num;
        for (int i = 0; i < n; i++) {
            num = nums[i];
            for (int j = target; j >= num; --j) {
                dp[j] |= dp[j - num];
            }
        }
        return dp[target];
    }
};
