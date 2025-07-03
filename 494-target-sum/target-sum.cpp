class Solution {
public:
    int key;
    int f(int i,int sum,vector<int>& nums)
    {
        if(i<0)
        {
            return sum==key;
        }
        int add=f(i-1,sum+nums[i],nums);
        int sub=f(i-1,sum-nums[i],nums);
        return add+sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        key=target;
        int n=nums.size();
        return f(n-1,0,nums);
    }
};