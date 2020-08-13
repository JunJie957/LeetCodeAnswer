class Solution {
public:
    int maxArea(vector<int>& height) {
        int L = 0, R = height.size() - 1, BestArea = 0;
        while (L < R) {
            BestArea = max(BestArea, min(height[R], height[L]) * (R - L));
            height[L] <= height[R] ? ++L : --R; // 总是较小者向内移动
        }
        return BestArea;
    }
};
