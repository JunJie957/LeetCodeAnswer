class Solution {
public:
	bool buddyStrings(string A, string B) {
		if (A.length() != B.length()) return false;

		bool is_double = false;
		unordered_map<char, int> um;
		int len = A.length(), loc = -1;
		for (int i = 0; i < len; ++i) {
			if (++um[A[i]] >= 2) is_double = true;
			if (A[i] != B[i]) {
				if (loc == -1) {
					loc = i;
				} else {
					swap(A[i], A[loc]);
					if (A.compare(B) == 0) return true;
					else return false;
				}
			}
		}
		if (is_double && A.compare(B) == 0) return true;
		return false;
	}
};
