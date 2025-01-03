class Solution {
public:
    int f(int i, int j,vector<vector<int>>& dp)
    {
        //base case
        if(i==0 && j==0)
        return 1;
        if(i<0 || j<0)
        return 0;

        if(dp[i][j]!=-1)
        return dp[i][j];

        int up=f(i-1,j,dp);
        int left=f(i,j-1,dp);
        return dp[i][j]=up+left;
    }
    int uniquePaths(int m, int n) {
        //topdown approach will be from [m-1][n-1] to [0][0] so moves up and left
        
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return f(m-1,n-1, dp);
    }
};