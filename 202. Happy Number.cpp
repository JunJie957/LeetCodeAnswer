class Solution {
public:
    bool isHappy(int n) 
    {  
        if (n < 0)
		  return false;

        if (n == 1)
            return true;
            
        int i = 0;
        int sum = 0;
        int tmp = 0;
        unordered_set<int> arr;

        string s = std::to_string(n);
        while (n != 1)
        {
            sum = 0;

            for (i = 0; i < s.size(); ++i)
                sum += ((s[i] - 48) * (s[i] - 48));

            if (arr.find(sum) != arr.end())
                return false;
            else
                arr.insert(sum);

            n = sum;
            s = std::to_string(sum);
        }

        if (n == 1)
            return true;
        
        return false;
    }
};