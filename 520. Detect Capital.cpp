class Solution {
public:
	bool detectCapitalUse(string word) {
		int size = word.length();
		if (size == 1) return true;
		if (islower(word[0]) && isupper(word[1])) return false;
			
		bool flag = true; // ��д
		if ((isupper(word[0]) && islower(word[1])) || (islower(word[0]) && islower(word[1])))
			flag = false; // һ����д��һ��Сд ���� ��������Сд��˵���������ĸ���붼��Сд

		// ������ĸ�Ĵ�СдҪ���жϺ������ĸ�Ƿ����
		for (int i = 2; i < size; ++i) {
			if ((flag && islower(word[i])) || (!flag && isupper(word[i]))) 
				return false;
		}
		return true;
	}
};
