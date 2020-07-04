class Solution {
public:
    bool isIsomorphic(string s, string t) {
       for (int index = 0; index < s.size(); ++index)
            if (s.find(s[index]) != t.find(t[index])) return false;
        return true;
    }
};