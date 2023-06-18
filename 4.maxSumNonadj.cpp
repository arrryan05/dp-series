class Solution{
public:	
	int solve(int *arr,int i,vector<int>& dp){
	    if(dp[i]!=-1) return dp[i];
	    if(i==0) return arr[i];
	    if(i<0) return 0;
	    int pick = arr[i]+solve(arr,i-2,dp);
	    int nonpick = 0+solve(arr,i-1,dp);
	    return dp[i]=max(pick, nonpick);
	}
	int findMaxSum(int *arr, int n) {
	    // code here
	    vector<int> dp(n,-1);
	    return solve(arr,n-1,dp);
	}
};