class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size(),sum=0,maxsum=INT_MIN;
        for(int i=0;i<n;i++)  //kadane algo
        {
            if(sum<0)
            sum=0;
            sum+=nums[i];
            if(sum>maxsum)
            maxsum=sum;
            
        }
        return maxsum;
    }
};