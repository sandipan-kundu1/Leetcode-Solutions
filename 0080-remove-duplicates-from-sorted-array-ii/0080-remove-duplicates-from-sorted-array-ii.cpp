class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=0,l,x;
        int i=0;
        l=nums.size();
        while(i<l)
        {
            x=count(nums.begin(),nums.end(),nums[i]);
            if(x>=2)
            {
                nums[k++]=nums[k++]=nums[i];
                i=i+x;
            }
            else{
                nums[k++]=nums[i];
                i++;
            }
        }
        return k;
    }
};