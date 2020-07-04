class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return 0;
        else if (size == 1)  return nums[0];

        int first = nums[0], second = max(nums[0], nums[1]), temp;
        for (int i = 2; i < size; i++) {
            temp = second;
            second = max(first + nums[i], second);  // 选或者不选，状态转移方程，第k个结果取决于第k-1个结果和当前的结果
            first = temp;
        }
        return second;
    }
};