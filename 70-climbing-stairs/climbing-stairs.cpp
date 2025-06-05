class Solution {
public:
    int f(int ind,vector<int>& dp)
    {
        if(ind==1 || ind==2)
        return ind;

        if(dp[ind]!=-1)
        return dp[ind];
        int one=f(ind-1,dp);
        int two=f(ind-2,dp);
        return dp[ind]=one+two;
    }
    int climbStairs(int n) {
        if(n==1 || n==2)
        return n;
        vector<int> dp(n+1,-1);
        return f(n,dp);
    }
};