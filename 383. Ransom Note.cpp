class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
        int find[26] = { 0 };

        for (int i = 0; i < magazine.size(); ++i)
            ++find[magazine[i] - 'a'];

        for (int i = 0; i < ransomNote.size(); ++i)
            if (--find[ransomNote[i] - 'a'] < 0)
                return false;

        return true;
    }
};