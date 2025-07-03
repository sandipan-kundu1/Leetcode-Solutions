class Solution {
public:
    int dp[1002][1002];
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size(),m=text2.size();
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                int match=0,notmatch=0;
                if(text1[i-1]==text2[j-1])
                match=1+dp[i-1][j-1];
                else
                notmatch=max(dp[i][j-1], dp[i-1][j]);
                dp[i][j]=match+notmatch;
            }
        }
        return dp[n][m];
    }
};