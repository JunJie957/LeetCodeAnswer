#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    std::unordered_map<char, int> um = { {'I',1}, {'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000} };
    int romanToInt(string s) {
        int sum = 0;
        int len = s.size();
        for (int i = 0; i < len; ++i) {
            if (i + 1 < len && um[s[i]] < um[s[i + 1]]) {
                sum += um[s[i + 1]] - um[s[i]];
                ++i;
            } else {
                sum += um[s[i]];
            }
        }
        return sum;
    }
};