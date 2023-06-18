class Solution {
public:
    int climbStairs(int n) {
        int ans,prev2 = 1, prev =1;
        if(n<=1) return 1;
        for(int i=2;i<=n;i++){
            ans = prev + prev2;
            prev2 = prev;
            prev = ans;
        }
        return ans;
    }
};