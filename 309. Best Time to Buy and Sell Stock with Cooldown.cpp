class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        
        int hold = 0, buy = -prices[0], sell = numeric_limits<int>::min();
        for (int i = 1, end = prices.size(); i < end; ++i) {
            buy = max(buy, hold - prices[i]);
            hold = max(hold, sell);
            sell = buy + prices[i];
            
        }
        
        return max(hold, sell);
    }
};