class Solution {
public:
    bool isAnagram(string s, string t) {
        if (t.length() != s.length()) return false;
        std::vector<int> hash(26, 0);
        for (auto c : s) hash[c - 'a']++;
        for (auto& c : t) {
           if (hash[c - 'a'] == 0) {
               return false;
           }
           hash[c - 'a']--;
        }
        return true;
    }
};
