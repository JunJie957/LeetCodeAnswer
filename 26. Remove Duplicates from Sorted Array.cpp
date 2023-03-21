#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int index = 0, size = nums.size();
        for (int i = 1; i < size; ++i) {
            if (nums[i] != nums[index]) {
                if (i > index) {
                    nums[index + 1] = nums[i];
                }
                ++index;
            }
        }
        return index + 1;
    }
};
