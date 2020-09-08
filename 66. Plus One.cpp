// 注意考虑有无进位的情况即可 
class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		digits[digits.size() - 1] =  1 + digits.back();
		if (digits.back() < 10) {
			return digits;
		} else {
			digits[digits.size() - 1] -= 10;
			bool add = true;
			for (int i = digits.size() - 2; i >= 0; --i) {
				digits[i] += 1;
				if (digits[i] < 10) {
					add = false; break;
				} else {
					digits[i] -= 10;
				}
			}
			if (add) digits.insert(digits.begin(), 1);
		}
		return digits;
	}
};
