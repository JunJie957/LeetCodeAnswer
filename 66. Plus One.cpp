class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        for (int i = digits.size() - 1; i >= 0; --i) {
            if (++digits[i] >= 10) {
                digits[i] %= 10;
                continue;
            }
            else {
                break;
            }
        }

        if (digits[0] == 0) {
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};
