#include <string>

using namespace std;

class Solution {
public:
    pair<int, int > expand(const std::string& s, int left, int right) {
        int size = s.size();
        while (left >= 0 && right < size && s[left] == s[right]) {
            --left;
            ++right;
        }
        return {left + 1, right - 1};
    }

    string longestPalindrome(string s) {
        int start = 0, end = 0, size = s.length();
        for (int i = 0; i < size; ++i) {
            auto p1 = expand(s, i, i);
            auto p2 = expand(s, i , i + 1);
            if (p1.second - p1.first > end - start) {
                start = p1.first;
                end = p1.second;
            }
            if (p2.second - p2.first > end - start) {
                start = p2.first;
                end = p2.second;
            }
        }
        return s.substr(start, end - start + 1);
    }
};