class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size(),curmax=1,curmin=1,res=INT_MIN;
        for(int i:nums)   //kadane algo
        {
            if(curmax==0)  curmax=1;
            if(curmin==0)  curmin=1;
            int temp=i*curmax;
            curmax=max({temp,i*curmin,i});
            curmin=min({temp,i*curmin,i});
            res=max(curmax,res);
        }
        return res;
    }
};