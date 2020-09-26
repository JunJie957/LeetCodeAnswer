class Solution {
public:
    int countSegments(string s) {
        int size = s.length(), count = 0;
        for (int i = 0; i < size; ++i) {
            if ((i == 0 || s[i - 1] == ' ') && s[i] != ' ') ++count;
        }
        return count;
    }
};
