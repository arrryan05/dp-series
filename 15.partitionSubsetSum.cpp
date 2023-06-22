class Solution {
public:
    bool solve(int ind, int target, vector<int>& nums, vector<vector<int>> &dp){
    if(target==0)
        return true;
    if(ind == 0)
        return nums[0] == target;
    if(dp[ind][target]!=-1)
        return dp[ind][target];
    bool notTaken = solve(ind-1,target,nums,dp);
    bool taken = false;
    if(nums[ind]<=target)
        taken = solve(ind-1,target-nums[ind],nums,dp);
    return dp[ind][target]= notTaken||taken;
}
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total_sum = 0;
        for(int i=0;i<nums.size();i++){
            total_sum += nums[i];
        }
        if(total_sum%2==1) return false;
        else{
            int k = total_sum/2;
            vector<vector<int>> dp(n,vector<int>(k+1,-1));
            return solve(n-1,k,nums,dp);
        }
    }
};