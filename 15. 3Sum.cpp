

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
       
        vector<vector<int>> res;
        int left, right, sum, size = nums.size();
        
        for (int i = 0; i < size; ++i) {
            if (nums[i] > 0) {
                return res; // 当剩余有序数组的首元素为正数时，不可能存在三个元素的和为零的情况
            }

            if (i > 0 && nums[i] == nums[i - 1]) {
                continue; // 去除重复元素
            }

            left = i + 1;       // 左边界
            right = size - 1;   // 右边界
            while (left < right) {
                sum = nums[i] + nums[left] + nums[right];
                if (sum > 0) {
                    --right; // 三数之和大于0，右指针左移
                }
                else if (sum < 0) {
                    ++left; // 三数之和小于0，左指针右移
                }
                else {
                    res.push_back({ nums[i],nums[left],nums[right] });

                    // 当有一组数被选中后，就需要进行去除左右重复元素的操作了，避免重复数组
                    while (right > left && nums[left] == nums[left + 1]) ++left;
                    while (right > left && nums[right] == nums[right - 1]) --right;

                    // 左右指针收紧，进行下一组数据判断
                    ++left;
                    --right;
                }
            }
        }
        return res;
    }
};

