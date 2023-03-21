#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        int maxStr = 0; // 最长子串
        int start = 0;  // 起始位置
        int size = s.length(); // 字符串长度
        std::vector<int> last(128, -1); // key - 字符, value - 下标
        for (int i = 0; i < size; ++i) {
            start = max(start, last[s[i]] + 1);
            maxStr = max(maxStr, i - start + 1);
            last[s[i]] = i;
        }
        return maxStr;
    }
};
