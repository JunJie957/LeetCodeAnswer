// 方法1
class Solution {
public:
	bool backspaceCompare(string S, string T) {
		int i = S.length(), j = T.length(), skipS = 0, skipT = 0;
		while (i >= 0 || j >= 0) {
			while (i >= 0) {
				if (S[i] == '#') { ++skipS, --i; }
				else if (skipS > 0) { --skipS; --i; }
				else break;
			}

			while (j >= 0) {
				if (T[j] == '#') { ++skipT, --j; }
				else if (skipT > 0) { --skipT; --j; }
				else break; 
			}

			if (i >= 0 && j >= 0 && S[i] != T[j]) return false;
			if ((i >= 0) != (j >= 0)) return false;
			--i, --j;
		}
		return true;
	}
};

// 方法2 
class Solution {
public:
	bool backspaceCompare(string S, string T) {
		string s, t;
		for (int i = S.length() - 1, count = 0; i >= 0; --i) {
			if (S[i] == '#') {
				++count;
			} else if (count > 0) {
				--count;
			} else {
				s += S[i];
			}
		}

		for (int i = T.length() - 1, count = 0; i >= 0; --i) {
			if (T[i] == '#') {
				++count;
			} else if (count > 0) {
				--count;
			} else {
				t += T[i];
			}
		}
		if (s.compare(t) == 0) return true;
		return false;
	}
};
