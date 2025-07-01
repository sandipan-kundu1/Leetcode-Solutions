class Solution {
public:
    bool f(int i,int jump,vector<int>& stones,vector<vector<int>> &dp)
    {
        if(i==stones.size()-1)
        return true;
        if(i>=stones.size())
        return false;
        if(dp[i][jump]!=-1)
        return (bool)dp[i][jump];

        for(int k=jump-1;k<=jump+1;k++)
        {
            if(k>0)
            {
                int nextpos=stones[i]+k;
                if(count(stones.begin(),stones.end(),nextpos))
                {
                    int nextind=find(stones.begin(), stones.end(), nextpos) - stones.begin();
                    if(f(nextind, k, stones, dp))
                    {
                        return dp[i][jump]=true;
                    }
                }
            }
        }
        return dp[i][jump]=false;;

    }
    bool canCross(vector<int>& stones) {
        int n=stones.size();
        if((stones[1]-stones[0])!=1)
        return false;
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return f(stones[1],1,stones,dp);
    }
};