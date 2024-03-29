#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<int> temp;
        vector<vector<int>> ans;
        int i = 0, left = newInterval[0], right = newInterval[1], size = intervals.size();
        while (i < size) {
            // 寻找左边界
            if (intervals[i][1] < left) {
                ans.emplace_back(intervals[i++]);
                continue;
            }
            temp.emplace_back(min(intervals[i][0], left));

            // 寻找右边界
            while (i < size) {
                if (intervals[i][0] > right) {
                    temp.emplace_back(right);
                } else if (intervals[i][0] == right || intervals[i][1] >= right) {
                    temp.emplace_back(intervals[i++][1]);
                }
                if (temp.size() == 2) {
                    ans.emplace_back(temp);
                    break;
                }
                ++i;
            }
            if (temp.size() != 2) {
                temp.emplace_back(right);
                ans.emplace_back(temp);
            }

            while (i < size) ans.emplace_back(intervals[i++]);
            return ans;
        }
        ans.emplace_back(newInterval);
        return ans;
    }
};