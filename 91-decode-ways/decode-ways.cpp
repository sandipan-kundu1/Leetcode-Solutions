class Solution {
public:
    int f(int i,string s,vector<int>& dp)
    {
        int n=s.size();
        if(i==n)
        return 1;
        if(dp[i]!=-1)
        return dp[i];
        int singlepick=0,nextpick=0;
        if(s[i]!='0')
        singlepick=f(i+1,s,dp);
        if(i<n-1 && s[i]!='0')
        {
            int num=(s[i]-'0')*10+s[i+1]-'0';
            if(num<=26)
            nextpick=f(i+2,s,dp);

        }
        return dp[i]=singlepick+nextpick;

    }
    int numDecodings(string s) {
        vector<int> dp(s.size(),-1);
        return f(0,s,dp);
    }
};