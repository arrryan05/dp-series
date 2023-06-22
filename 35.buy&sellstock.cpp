class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int minm = prices[0];
        for(int i=1;i<prices.size();i++){
            int cost = prices[i]-minm;
            profit = max(profit, cost);
            minm = min(minm,prices[i]);
        }
        return profit;
    }
};