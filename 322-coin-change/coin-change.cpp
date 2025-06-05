class Solution {
public:
    int f(int i,vector<int>& coins, int tar,vector<vector<int>>& dp)
    {
        if(i==0)
        {
            if(tar%coins[0]==0)
            return tar/coins[0];
            return 1e9;//impossible to make coin combination
        }
        

        if(dp[i][tar]!=-1)
        return dp[i][tar];

        int take=INT_MAX;
        if(tar>=coins[i])
        take=1+f(i,coins,tar-coins[i],dp);
        int nottake=f(i-1,coins,tar,dp);
        return dp[i][tar]=min(take,nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0)
        return 0;
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        if(f(coins.size()-1,coins,amount,dp)<1e9)
        return f(coins.size()-1,coins,amount,dp);
        return -1;
    }
};