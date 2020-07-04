class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        auto iter = find(nums.begin(), nums.end(), target);
        if (iter != nums.end())
        {
            return iter - nums.begin();
        }
        else
        {
            int left = 0;
            int right = nums.size() - 1;
            int mid = right / 2 + 1;
            while (1)
            {
                if (nums[left] < target) left++;
                else return left;

                if (nums[right] > target)  right--;
                else return ++right;
                
                if (nums[mid] < target) left = mid;
                else right = mid;

                mid = right / 2 + 1;
            }
        }
    }
};