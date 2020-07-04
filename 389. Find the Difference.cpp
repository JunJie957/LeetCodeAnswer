class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> v(26, 0);

        int len = t.size();
        for (int i = 0; i < len; ++i) v[t[i] - 'a']++;

        len = s.size();
        for (int i = 0; i < len; ++i) v[s[i] - 'a']--;
            
        int i = 0;
        for (; i < 26; ++i) if (v[i] == 1) break;
            
        return 'a' + i;
    }
};