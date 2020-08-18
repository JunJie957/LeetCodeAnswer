class Solution {
public:
	string removeOuterParentheses(string S) {
		int size = S.size();
		string res, tmp;
		int count = 0;
		for (int i = 0; i < size; ++i) {
			if (S[i] == '(') 
				++count;
			else
				--count;

			tmp += S[i];
			if (count == 0) {
				res += tmp.substr(1, tmp.size() - 2);
				tmp.clear();
			}
		}
		return res;
	}
};
