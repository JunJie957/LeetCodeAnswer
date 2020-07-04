class Solution {
public:
    bool isPalindrome(string s) {
   
     string s1, s2;

    int len = s.length();
    for (int i = 0; i < len; ++i)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
            s1 += s[i];
        else if (s[i] >= 'A' && s[i] <= 'Z')
            s1 += s[i] + 32;
    }

    s2 = s1;
    reverse(s2.begin(), s2.end());
    if (s2.compare(s1) == 0) return true;
       
    return false;
    }
};