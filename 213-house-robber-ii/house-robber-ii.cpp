class Solution {
public:
    int robhelp(vector<int>& nums,int start, int end) {
        int n=nums.size();
        if(start==end)
        return nums[start];

        vector<int> dp(n);
        dp[start]=nums[start];
        dp[start+1]=max(nums[start], nums[start+1]);
        for(int i=start+2;i<=end;i++)
        {
            int pick=nums[i]+dp[i-2];
            int notpick=0+dp[i-1];
            dp[i]=max(pick, notpick);
        }
        return dp[end];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
        return nums[0];
        int first=robhelp(nums,0,n-2);
        int last=robhelp(nums,1,n-1);
        return max(first,last);
    }
};