class Solution {
public:
    int solve(int i,int s, int target, vector<int>& nums,int ts,vector<vector<int>>& dp){
        if(i==0){
            int x = s-ts;
            if(x+nums[0]==target || x-nums[0]==target) return !nums[0]?2:1;
            return 0; 
        }
        if(dp[i][s]!=-1) return dp[i][s];
        int subs = solve(i-1,s-nums[i],target,nums,ts,dp);
        int add = solve(i-1,s+nums[i],target,nums,ts,dp);
        return dp[i][s]=subs+add;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int total_sum = accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>> dp(n,vector<int>(2*total_sum+1,-1));
        return solve(n-1,total_sum,target,nums,total_sum,dp);
    }
};