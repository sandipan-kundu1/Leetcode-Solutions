class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,0);
        int posind=0,negind=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0)
            {
                ans[posind]=nums[i];
                posind+=2;
            }
            else{
                ans[negind]=nums[i];
                negind+=2;
            }
        }
        return ans;
    }
};