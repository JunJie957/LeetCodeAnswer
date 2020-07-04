class Solution {
public:
    bool isAnagram(string s, string t)
    {        
        if(s.length()!= t.length())
            return false;

        unsigned int test[26] = { 0 };
        unsigned int index = -1;

        for(int i = 0; i < s.length(); ++i)
        {
            index = s[i] - 'a';    // s的下标           
            test[index] += 1;   

            index = t[i] - 'a';    // t的下标
            test[index] -= 1;                                    
        }
        
        for(int i = 0; i < 26; ++i)
        {
            if(test[i] != 0)
            {
                return false;
            }
        }
        return true;
    }
};