class Solution {
public:
    int f(int ind,int prevind,vector<vector<int>>& dp,vector<int>& nums)
    {
        if(ind==nums.size())
        return 0; //going left to right bottom up

        if(dp[ind][prevind+1]!=-1)
        return dp[ind][prevind+1];

        int take=0,nottake=0;
        nottake=f(ind+1,prevind,dp,nums);
        if(prevind==-1 || nums[ind]>nums[prevind])
        take=1+f(ind+1,ind,dp,nums);
        return dp[ind][prevind+1]=max(take,nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return f(0,-1,dp,nums);
    }
};