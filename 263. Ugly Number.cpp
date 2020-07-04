class Solution {
public:
    bool isUgly(int num) {
        if(num <= 0) return false;

        vector<int> v{2,3,5};
        for(auto i : v)
        {
            while(num % i == 0)
            {
                num /= i;
            }
        }

        if(num == 1) return true;
        return false;
    }
};