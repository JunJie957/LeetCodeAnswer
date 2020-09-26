// ¶¯Ì¬¹æ»®
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum, ans = nums[0];
        for (auto& num : nums) {
            if (sum > 0) {
                sum += num;
            }
            else {
                sum = num;
            }
            if (sum > ans) ans = sum;
        }
        return ans;
    }
};
