class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int size = nums.size(), ans = 10000000, left, right, sum;
        for (int i = 0; i < size - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            left = i + 1, right = size - 1;
            while (left < right) {
                sum = nums[i] + nums[right] + nums[left];
                if (sum == target) return target;
                else if (sum < target) ++left;
                else --right;
                if (abs(sum - target) < abs(ans - target)) ans = sum;
            }
        }
        return ans;
    }
};

