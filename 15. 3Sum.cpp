class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int size = nums.size();
        for (int i = 0; i < size - 2; ++i) {
            if (nums[i] > 0) return res;
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int left = i + 1, right = size - 1;
            while (left < right) {
                int sum = nums[left] + nums[right] + nums[i];
                if (sum > 0) --right;
                else if (sum < 0) ++left;
                else {
                    res.push_back({ nums[i],nums[left],nums[right] });
                    while (left < right && nums[left] == nums[++left]);
                    while (left < right && nums[right] == nums[--right]);
                }
            }
        }
        return res;
    }
};
