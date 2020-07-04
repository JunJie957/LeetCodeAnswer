class Solution {
public:
    string convertToTitle(int n) {
        string res;
        while (n != 0 )
        {
            if (n % 26 == 0)
            {
                res += 'Z';
                n /= 26;
                --n;
            }
            else
            {
                res += n % 26 - 1 + 'A';
                n /= 26;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};