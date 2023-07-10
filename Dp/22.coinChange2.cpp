class Solution {
public:
    int solve(int i,int amount,vector<int>& coins,vector<vector<int>>& dp){
        if(i==0){
            if (amount == 0) return 1;
            if(amount%coins[0]==0) return 1;
            else return 0;
        }
        if(dp[i][amount]!=-1) return dp[i][amount];
        int notTake = solve(i-1,amount,coins,dp);
        int take = 0;
        if(amount>=coins[i]){
            take = solve(i-1,amount-coins[i],coins,dp);
        }
        return dp[i][amount]=take+notTake;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
        return solve(n,amount,coins,dp);
    }
};