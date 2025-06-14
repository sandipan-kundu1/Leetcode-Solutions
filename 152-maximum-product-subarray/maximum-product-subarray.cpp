class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size(),prefix=1,suffix=1,res=INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(prefix==0)
            prefix=1;
            prefix*=nums[i];
            if(suffix==0)
            suffix=1;
            suffix*=nums[n-1-i];
            res=max({res,prefix,suffix});
        }
        return res;
    }
};