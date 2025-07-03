class Solution {
public:
    int key;
    int total;
    int dp[21][2001];
    int f(int i,int sum,vector<int>& nums)
    {
        if(i<0)
        {
            return sum==key;
        }
        if(dp[i][sum+total]!=-1)
        return dp[i][sum+total];
        
        int add=f(i-1,sum+nums[i],nums);
        int sub=f(i-1,sum-nums[i],nums);
        return dp[i][sum+total]= add+sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        key=target;
        int n=nums.size();
        total=accumulate(nums.begin(),nums.end(),0);
        memset(dp,-1,sizeof(dp));
        return f(n-1,0,nums);
    }
};