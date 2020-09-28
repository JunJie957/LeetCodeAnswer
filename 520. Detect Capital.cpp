class Solution {
public:
	bool detectCapitalUse(string word) {
		int size = word.length();
		if (size == 1) return true;
		if (islower(word[0]) && isupper(word[1])) return false;
			
		bool flag = true; // 大写
		if ((isupper(word[0]) && islower(word[1])) || (islower(word[0]) && islower(word[1])))
			flag = false; // 一个大写，一个小写 或者 两个都是小写，说明后面的字母必须都是小写

		// 根据字母的大小写要求，判断后面的字母是否符合
		for (int i = 2; i < size; ++i) {
			if ((flag && islower(word[i])) || (!flag && isupper(word[i]))) 
				return false;
		}
		return true;
	}
};
