#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        std::string s = std::to_string(x), res;
        int len = s.length(), start = len - 1;

        if (s[0] == '-')
            res += "-";
        while (start > 0 && s[start] == '0')
            --start;
        while (start > 0)
            res += s[start--];
        if (s[0] != '-')
            res += s[0];

        auto num = std::atoll(res.c_str());
        if (num > pow(2, 31) - 1 || num < pow(-2, 31)) {
            return 0;
        }
        return num;
    }
};