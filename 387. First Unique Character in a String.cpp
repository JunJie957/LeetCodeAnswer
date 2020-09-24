class Solution {
public:
	int firstUniqChar(string s) {
		int size = s.size();
		pair<int,int> letter[26];
		for (int i = 0; i < size; ++i) {
			++letter[s[i] - 'a'].first;
			letter[s[i] - 'a'].second = i;
		}

		int min_loc = -1;
		for (auto i : letter) {
			if (i.first == 1 && (min_loc == -1 || i.second < min_loc)) {
					min_loc = i.second;
			}
		}
		return min_loc;
	}
};
