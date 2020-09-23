class Solution {
public:
	bool repeatedSubstringPattern(string s) {
		int len = s.length();
		for (int i = 1; i <= len / 2; ++i) {
			if (s[i] == s[0] && len % i == 0) {
				int multi = len / i - 1;
				string sub = s.substr(0, i), tmp = sub;
				while (multi-- > 0) sub += tmp;
				if (sub.compare(s) == 0) return true;
			}
		}
		return false;
	}
};
