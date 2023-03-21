#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        std::unordered_map<int, int> hash;
        for (int i = 0; i < size; ++i) {
            int r = target - nums[i];
            if (hash.count(r)) {
                return {hash[r], i};
            }
            hash[nums[i]] = i; // 记录下标
        }
        return {};
    }
};