class Solution {
public:
    int solve(vector<int>& prices,int i,int buy,int n,vector<vector<int>>& dp){
        if(i>=n) return 0;
        int profit;
        if(dp[i][buy]!=-1)
            return dp[i][buy];
        if(buy==0){
            profit = max(0+solve(prices,i+1,0,n,dp), -prices[i]+solve(prices,i+1,1,n,dp));
        }
        if(buy==1){
            profit = max(0+solve(prices,i+1,1,n,dp), prices[i]+solve(prices,i+2,0,n,dp));
        }
        return dp[i][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(prices,0,0,n,dp);
    }
};