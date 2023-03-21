#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int len = s.length();
        bool signal = false;
        bool no_space = false;
        std::string res;
        for (int i = 0; i < len; ++i) {
            // find space
            if (s[i] == ' ' && !no_space) {
                continue;
            }
            no_space = true;

            // signal
            if (s[i] == '+' || s[i] == '-') {
                if (!signal) {
                    res += s[i];
                    signal = true;
                    continue;
                } else {
                    break;
                }
            }

            // number
            if (s[i] >= '0' && s[i] <= '9') {
                res += s[i];
            } else {
                break;
            }
        }

        if (res.empty() || (res.size() == 1 && (res[0] == '+' || res[0] == '0'))) {
            res = '0';
        }
        auto num = atoll(res.c_str());
        if (num < -2147483648) {
            return -2147483648;
        } else if (num > 2147483647) {
            return 2147483647;
        }
        return num;
    }
};