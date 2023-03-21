#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <istream>

using namespace std;

class Solution {
public:
    void backtrack(const vector<int>& nums, const int& start, const int& subSize, vector<int>& sub) {
        if (sub.size() == subSize) {
            ans.emplace_back(sub);
            return;
        }
        for (int i = start; i < size; ++i) {
            sub.emplace_back(nums[i]);
            backtrack(nums, i + 1, subSize, sub);
            sub.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        size = nums.size();
        for (int i = 0; i <= size; ++i) {
            sub.clear();
            backtrack(nums, 0, i, sub);
        }
        return ans;
    }
private:
    int size;
    vector<int> sub;
    vector<vector<int>> ans;
};
