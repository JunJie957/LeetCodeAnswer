#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        } else if (strs.size() == 1) {
            return strs[0];
        }

        std::sort(strs.begin(), strs.end());
        std::string begin = strs.front(), end = strs.back();
        int i = 0, size = std::min(begin.size(), end.size());
        while (i < size && begin[i] == end[i]) {
            ++i;
        }
        return begin.substr(0, i);
    }
};