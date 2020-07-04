class Solution {
public:
    bool isPowerOfTwo(int n) {
  if (n == 0) return false;
	else if (n > 0)
	{
		while (n != 1)
		{
			if (n % 2 == 1) return false;
			n /= 2;
		}
	}
	else
	{
		while (n != 0)
		{
			if (n % 2 == -1) return false;
			n /= 2;
		}
	}
	return true;
    }
};