class Solution {
public:
    int getAns(vector<int>& Arr, int n, int ind, int buy, int cap, vector<vector<vector<int>>>& dp ){
    if(ind==n || cap==0) return 0;
    if(dp[ind][buy][cap]!=-1)
        return dp[ind][buy][cap];
    int profit;
    if(buy==0){
        profit = max(0+getAns(Arr,n,ind+1,0,cap,dp), 
                    -Arr[ind] + getAns(Arr,n,ind+1,1,cap,dp));
    }
    if(buy==1){
        profit = max(0+getAns(Arr,n,ind+1,1,cap,dp),
                    Arr[ind] + getAns(Arr,n,ind+1,0,cap-1,dp));
    }
    return dp[ind][buy][cap] = profit;
}

    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(3,-1)));
        return getAns(prices,prices.size(),0,0,2,dp);
    }
};