class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        int v = digits[len - 1];
        v += 1;
        if (v < 10) digits[len - 1] = v;
        else
        {
            digits[len - 1] = v % 10;
            for (int i = len - 2; i >= 0; --i)
            {
                v = digits[i] + v / 10;
                if (v < 10)
                {
                    digits[i] = v;
                    break;
                }
                else digits[i] = v % 10;
                    
            }
            if (v >= 10) digits.insert(digits.begin(), v / 10);
        }
        return digits;
    }
};