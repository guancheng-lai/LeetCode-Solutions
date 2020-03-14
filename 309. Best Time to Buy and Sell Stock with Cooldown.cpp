class Solution {
public:
    int maxProfit(vector<int>& prices) {
        size_t len = prices.size();
        if (len <= 1) return 0;
        
        vector<int> buy(len), sell(len);
        buy[0] = -prices[0], sell[0] = 0;
        buy[1] = max( buy[0],-prices[1] ), sell[1] = max( sell[0],buy[0]+prices[1] );
        
        for (int i = 2; i < len; ++i) {
            buy[i] = max( buy[i-1],sell[i-2]-prices[i] );
            sell[i] = max( sell[i-1],buy[i-1]+prices[i] );
        }
        
        return sell.back();
    }
};