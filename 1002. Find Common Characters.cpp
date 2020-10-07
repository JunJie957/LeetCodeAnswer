class Solution {
public:
	vector<string> commonChars(vector<string>& A) {
		vector<string> res;
		int num[100][26] = { 0 };
		for (int i = 0; i < A.size(); ++i) {
			for (int j = 0; j < A[i].size(); ++j) {
				++num[i][A[i][j] - 'a'];
			}
		}

		for (int j = 0; j < 26; ++j) {
			for (int i = 1; i < A.size(); ++i) {
				num[0][j] = min(num[0][j], num[i][j]);
			}
		}

		string str;
		for (int i = 0; i < 26; ++i) {
			while (num[0][i]-- > 0) {
				str.clear();
				str += 'a' + i;
				res.emplace_back(str);
			}
		}
		return res;
	}
};
