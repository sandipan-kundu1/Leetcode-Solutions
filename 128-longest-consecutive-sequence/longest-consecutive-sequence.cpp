class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int lastsmaller=INT_MIN;
        int cnt=0,longest=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]-1==lastsmaller)
            {
                cnt+=1;
                lastsmaller=nums[i];
            }
            else if(nums[i]!=lastsmaller){
                
                cnt=1;
                lastsmaller=nums[i];
            }
            longest=max(longest,cnt);
        }
        return longest;
    }
};