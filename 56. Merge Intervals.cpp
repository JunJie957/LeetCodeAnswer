#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        for (auto& i : intervals) {
            if (ans.empty() || ans.back()[1] < i.front()) {
                ans.emplace_back(i);
            } else {
                ans.back()[1] = max(ans.back()[1], i.back());
            }
        }
        return ans;
    }
};

