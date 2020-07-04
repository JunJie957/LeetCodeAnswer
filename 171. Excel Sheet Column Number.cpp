class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        int count = 0;
        int size = s.length();
        for (int i = size - 1; i >= 0 ; --i)
        { 
            res += pow(26, count++) * (s[i] - 'A' + 1);
        }
        return res;
    }
};