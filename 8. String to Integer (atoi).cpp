class Solution {
public:
    int myAtoi(string str) {
		int len = str.size();
		bool find_sign = false;
		bool find_no_space = false;
		string res("");
		for (int i = 0; i < len; ++i)
		{
			if (str[i] == ' ' && find_no_space == false)
				continue;

			find_no_space = true;
			if (str[i] == '+' || str[i] == '-')
			{
				if (find_sign == false)
				{
					res += str[i];
					find_sign = true;
					continue;
				}
				else
				{
					break;
				}
			}

			if (str[i] >= '0' && str[i] <= '9')
			{
				res += str[i];
			}
			else
			{
				break;
			}
		}
		if (res.empty() || (res.size() == 1 && (res[0] == '+' || res[0] == '-'))) res = '0';
		else
		{
			if (atoll(res.c_str()) < -2147483648) res = "-2147483648";
			else if(atoll(res.c_str()) > 2147483647) res = "2147483647";
		}
		return atoi(res.c_str());
    }
};