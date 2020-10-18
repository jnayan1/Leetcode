class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int sz = prices.size();
        if(k == 0 or sz == 0 or sz == 1)
            return 0;
        if(k>=sz/2) {
            int maxProfit = 0;
            for(int i=0;i<sz-1;i++)
                maxProfit += max(0, prices[i+1]-prices[i]);
            return maxProfit;
        }
        vector<int> buy(k, INT_MIN);
        vector<int> sell(k, INT_MIN);
        for(int i=0;i<sz;i++) {
            for(int j=0;j<k;j++) {
                buy[j] = max(buy[j], (j==0)?0-prices[i]:sell[j-1]-prices[i]);
                sell[j] = max(sell[j], buy[j]+prices[i]);
            }
        }
        return sell[k-1];
    }
};