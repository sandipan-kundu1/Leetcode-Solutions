class Solution {
public:
    
    // int f(int ind,vector<int>& dp, vector<int>& nums)
    // {
    //     if(ind<0)
    //     return 0;

    //     if(dp[ind]!=-1)
    //     return dp[ind];

    //     int take=nums[ind]+f(ind-2,dp,nums);
    //     int nottake=f(ind-1,dp,nums);
    //     return max(take,nottake);
    //}
    int robhelp(int start,int end,vector<int> &nums)
    {
        if(start==end)
        return nums[start];
        
        vector<int> dp(nums.size(),-1);
        dp[start]=nums[start];
        dp[start+1]=max(nums[start],nums[start+1]);
        for(int i=start+2;i<=end;i++)
        {
            int take=nums[i]+dp[i-2];
            int nottake=dp[i-1];
            dp[i]=max(take,nottake);
        }
        return dp[end];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
        return nums[0];

        int first=robhelp(0,n-2,nums);
        int last=robhelp(1,n-1,nums);
        return max(first,last);
    }
};