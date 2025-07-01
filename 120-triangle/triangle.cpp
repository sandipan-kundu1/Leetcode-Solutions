class Solution {
public:
    int f(int row,int col,vector<vector<int>>& triangle,vector<vector<int>>& dp)
    {
        if(row==0)
        return triangle[0][0];

        if(dp[row][col]!=-1)
        return dp[row][col];

        int way1=INT_MAX,way2=INT_MAX;
        if(col<triangle[row].size()-1)
        way1=triangle[row][col]+f(row-1,col,triangle,dp);
        if(col>0)
        way2=triangle[row][col]+f(row-1,col-1,triangle,dp);
        return dp[row][col]=min(way1,way2);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int m=triangle[n-1].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int mini=INT_MAX;
        for(int i=0;i<m;i++)
        mini=min(mini,f(n-1,i,triangle,dp));
        return mini;
    }
};