#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int len;
    vector<vector<int>> res;

    void backtrace(vector<int>& nums, int loc) {
        if (loc == len) {
            res.emplace_back(nums);
            return;
        }
        for (int i = loc; i < len; ++i) {
            swap(nums[i], nums[loc]);
            backtrace(nums, loc + 1);
            swap(nums[i], nums[loc]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        len = nums.size();
        backtrace(nums, 0);
        return res;
    }
};