#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1, best = 0;
        while (left < right) {
            best = max(best, min(height[right], height[left]) * (right - left));
            height[left] <= height[right] ? ++left : --right;
        }
        return best;
    }
};
