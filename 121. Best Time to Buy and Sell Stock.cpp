class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int minprice = prices[0], maxprofit = 0;
        for (int price : prices){
            maxprofit = max(maxprofit, price - minprice); // 更新最大利润值
            minprice =  min(minprice, price); // 更新最低股价值
        }
        return maxprofit;
    }
};