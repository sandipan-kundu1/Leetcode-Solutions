class Solution {
public:
    int total;
    bool f(int i,int sum,vector<int>& nums,vector<vector<int>>& dp)
    {
        if(i<0)
        return sum==total/2;

        if(dp[i][sum]!=-1)
        return (bool)dp[i][sum];
        bool take=f(i-1,sum+nums[i],nums,dp);
        bool nottake=f(i-1,sum,nums,dp);
        return dp[i][sum]= (int)(take || nottake);
    }
    bool canPartition(vector<int>& nums) {
        total=accumulate(nums.begin(),nums.end(),0);
        if(total & 1)   return false;
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(total+1,-1));
        return f(nums.size()-1,0,nums,dp);
    }
};