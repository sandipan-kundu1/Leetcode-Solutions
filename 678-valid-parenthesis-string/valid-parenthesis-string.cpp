class Solution {
public:
    bool f(int i,int cnt,string s,vector<vector<int>>& dp)
    {
        if(i==s.size())
        return cnt==0;
        if(cnt<0)
        return false;

        if(dp[i][cnt]!=-1)
        return (bool)dp[i][cnt];
        if(s[i]=='(')
        return dp[i][cnt]= (int)f(i+1,cnt+1,s,dp);
        if(s[i]==')')
        return dp[i][cnt]=(int) f(i+1,cnt-1,s,dp);

        return dp[i][cnt]=(int)( f(i+1,cnt+1,s,dp) || f(i+1,cnt,s,dp) || f(i+1,cnt-1,s,dp) );
    }
    bool checkValidString(string s) {
        vector<vector<int>> dp(s.size(),vector<int>(s.size(),-1));
        return f(0,0,s,dp);
    }
};