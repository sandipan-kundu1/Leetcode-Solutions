class Solution {
public:
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> dp(n,vector<int>(n));

        for(int j=0;j<n;j++)
        dp[0][j]=matrix[0][j];
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int up=1e8,ld=1e8,rd=1e8;
                up=matrix[i][j]+ dp[i-1][j];
                if(j>0) ld=matrix[i][j]+ dp[i-1][j-1];
                if(j<n-1) rd=matrix[i][j]+ dp[i-1][j+1];
                dp[i][j]=min({up,ld,rd});
            }
        }
        int mini=dp[n-1][0];
        for(int j=1;j<n;j++)
        mini=min(mini, dp[n-1][j]);
        return mini;
    }
};