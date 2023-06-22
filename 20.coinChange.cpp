class Solution {
public:
    int solve(int i, int amt, vector<int>& coins) {
    if (i == 0) {
        if (amt == 0) return 0;
        else if (amt % coins[0] == 0) return amt / coins[0];
        else return INT_MAX;
    }
    int notTaken = INT_MAX;
    if(amt>=0) notTaken = 0 + solve(i-1, amt, coins);
    int taken = INT_MAX;
    if (amt >= coins[i]) {
        taken = 1 + solve(i-1, amt-coins[i], coins);
    }
    return min(taken, notTaken);
}

int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    int ans = solve(n - 1, amount, coins);
    if (ans == INT_MAX) return -1;
    else return ans;
}

};