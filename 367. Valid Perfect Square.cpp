class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 1) return true;
        if (num == 2) return false;

        int left = 2, right = num / 2;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int div = num / mid;
            if (div == mid) {
                if (num % div == 0) return true;
                left = mid + 1;
            } else if (div > mid) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }
};
