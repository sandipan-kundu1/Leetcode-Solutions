class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xor1=0,xor2=0;
        int n=nums.size();
        for(int i=1;i<=n;i++)
            xor1=xor1^i;
        for(int i:nums)
            xor2=xor2^i;
        return xor1^xor2;
    }
};