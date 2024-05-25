class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int l=nums.size();
        if(l==1)
            return true;
        else{
            for(int i=0;i<l-1;i++)
            {
                if(nums[i]%2==0 && nums[i+1]%2==0)
                    return false;
                else if(nums[i]%2==1 && nums[i+1]%2==1)
                    return false;
            }
            return true;
        }
    }
};