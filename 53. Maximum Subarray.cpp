#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre = 0, maxAns = nums[0];
        for (const auto& num : nums) {
            // 动态规划转移方程
            pre = max(pre + num, num);
            // 当前最大连续子数组的和
            maxAns = max(maxAns, pre);
        }
        return maxAns;
    }
};