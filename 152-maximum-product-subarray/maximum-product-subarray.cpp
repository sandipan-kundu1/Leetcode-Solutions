class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size(),prefix=0,suffix=0,res=INT_MIN;
        for(int i=0;i<n;i++)
        {
            prefix=nums[i]* (prefix==0? 1: prefix);
            suffix=nums[n-1-i]* (suffix==0? 1:suffix);
            res=max({res,prefix,suffix});
        }
        return res;
    }
};