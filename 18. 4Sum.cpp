#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int size = nums.size();
        for (int i = 0; i < size - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            if ((long long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;
            if ((long long)nums[i] + nums[size - 3] + nums[size - 2] + nums[size - 1] < target) continue;
            for (int j = i + 1; j < size - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                if ((long long)nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break;
                if ((long long)nums[i] + nums[j] + nums[size - 2] + nums[size - 1] < target) continue;
                int left = j + 1, right = size - 1;
                while (left < right) {
                    auto sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum > target) --right;
                    else if (sum < target) ++left;
                    else {
                        res.emplace_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[++left]);
                        while (left < right && nums[right] == nums[--right]);
                    }
                }
            }
        }
        return res;
    }
};