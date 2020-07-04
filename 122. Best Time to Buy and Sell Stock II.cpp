class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int sum = 0, cur = prices[0], size = prices.size();
        for (int i = 1; i < size; ++i) {
            if (prices[i] > cur) sum += prices[i] - cur;
            cur = prices[i];
        }
        return sum;
    }
};