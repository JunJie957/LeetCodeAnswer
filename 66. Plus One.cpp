#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <istream>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        digits.back() += 1;
        if (digits.back() < 10) {
            return digits;
        } else {
            digits.back() -= 10;
            bool add = true;
            for (int i = digits.size() - 2; i >= 0; --i) {
                digits[i] += 1;
                if (digits[i] < 10) {
                    add = false;
                    break;
                } else {
                    digits[i] -= 10;
                }
            }
            if (add) {
                digits.insert(digits.begin(), 1);
            }
            return digits;
        }
    }
};