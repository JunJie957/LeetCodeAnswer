class Solution {
public:
vector<int> resolve(int num)
	{
		int res1 = num, res2 = 1;
		int div = res1 - res2;
		for (int i = sqrt(num); i >= 2; --i)
		{
			if (num % i == 0)
			{
				if (abs(i - (num / i)) < div)
				{
					res1 = i;
					res2 = num / i;
					div = abs(res1 - res2);
				}
			}
		}
		return { res1,res2 };
	}
    vector<int> closestDivisors(int num)
    {
        vector<int> res1(2,0), res2(2,0);
		res1 = resolve(num + 1);
		res2 = resolve(num + 2);
		return abs(res1[0] - res1[1]) < abs(res2[0] - res2[1]) ? res1 : res2;

    }
};