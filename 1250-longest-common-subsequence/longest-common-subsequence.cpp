class Solution {
public:
    // int f(int i,int j,vector<vector<int>>& dp,string text1, string text2)
    // {
    //     if(i<0 || j<0)
    //     return 0;
    //     if(i==0 && j==0 && text1[i]==text2[j])
    //     return 1;
    //     if(dp[i][j]!=-1)
    //     return dp[i][j];

    //     int match=0,notmatch=0;
    //     if(text1[i]==text2[j])
    //     match=1+f(i-1,j-1,dp,text1,text2);
    //     else
    //     notmatch=max(f(i-1,j,dp,text1,text2), f(i,j-1,dp,text1,text2));

    //     return dp[i][j]=max(match,notmatch);
    // }
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size(),n2=text2.size();
        vector<vector<int>> dp(n1,vector<int>(n2,0));

        dp[0][0]=(text1[0]==text2[0]?1:0);
        for(int i=0;i<n1;i++)
        {
            for(int j=0;j<n2;j++)
            {
                int match=0,notmatch=0;
                if(text1[i]==text2[j])
                match=1+((i>0 && j>0)?dp[i-1][j-1]:0);
                else
                notmatch=max(
                    ((i>0)? dp[i-1][j] :0), 
                    ((j>0)? dp[i][j-1] :0)
                );
                dp[i][j]=max(match,notmatch);
            }
        }
        return dp[n1-1][n2-1];
    }
};