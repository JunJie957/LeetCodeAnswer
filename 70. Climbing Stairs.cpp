class Solution {
public:
    int climbStairs(int n) {
        int x = 0, y = 0, z = 1;
        for (int i = n; i >= 1; --i)
        {
            x = y;
            y = z;
            z = x + y;
        }
        return z;
    }
};