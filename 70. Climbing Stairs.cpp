#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <istream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        int f1 = 1, f2 = 2, f3 = 3;
        for (int i = 3; i <= n; ++i) {
            f3 = f2 + f1;
            f1 = f2;
            f2 = f3;
        }
        return f3;
    }
};
