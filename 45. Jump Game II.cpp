#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int right = 0;
        int preRight = 0;
        int step = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (i <= right) {
                right = max(right, i + nums[i]);
                if (i == preRight) {
                    ++step;
                    preRight = right;
                }
            }
        }
        return step;
    }
};

