class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1)
        return nums[0];
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=nums[i+1] && i!=nums.size()-1)
            return nums[i];
            else if(i==nums.size()-1)
            return nums[i];
            else
            i++;
        }
        return -1;
    }
};