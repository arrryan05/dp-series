int FindMaxSum(int arr[], int n)
{ // Your code here
    vector<int> dp(n);
    dp[0] = arr[0];
    if (n > 1)
        dp[1] = max(arr[0], arr[1]);
    for (int i = 2; i < n; i++)
    {
        int rob = arr[i] + dp[i - 2];
        int notrob = dp[i - 1];
        dp[i] = max(rob, notrob);
    }

    return dp[n - 1];
}