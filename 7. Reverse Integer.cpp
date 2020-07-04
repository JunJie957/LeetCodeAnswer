class Solution {
public:
    int reverse(int x) {
  string str = to_string(x);
	string result("");
	int len = str.size();
	bool find_zero = true;

	if (str[0] == '-') result += "-";
	for (int i = len - 1; i > 0; --i)
	{
		if (str[i] == '0' && find_zero) continue;
		else
		{
			result += str[i];
			find_zero = false;
		}
	}
	if (str[0] != '-') result += str[0];

	if (atoll(result.c_str()) > pow(2, 31) - 1 || atoll(result.c_str()) < pow(-2, 31))
		result = "0";
	
	return atoi(result.c_str());
    }
};