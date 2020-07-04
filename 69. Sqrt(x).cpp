class Solution {
public:
    int mySqrt(int x) {
        
        int left = 1;
        int right = x - 1;
        int mid = x / 2 + 1;
        while (1)
        {
            if (left > x / left) return --left;
            else if (left < x / left) ++left;
            else if (left == x / left) return left;

            if (right> x / right) --right;
            else if (right <= x / right) return right;

            if (mid == x / mid) return mid;
            else if (mid > x / mid) right = mid;
            else if (mid < x / mid) left = mid;
            
            mid = mid / 2 + 1;
        }
        return 0;
    }
};