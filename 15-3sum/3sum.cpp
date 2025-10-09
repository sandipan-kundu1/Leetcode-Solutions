class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> res;
        if(n<3) return res;
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++)
        {
            if(i>0 && nums[i]==nums[i-1])    continue;
            int target=-nums[i];
            int left=i+1,right=n-1;
            while(left<right)
            {
                int l=nums[left],r=nums[right];
                int sum=l+r;
                if(target==sum)
                {
                    res.push_back({nums[i],nums[left],nums[right]});
                    while(left<right && nums[left]==l)
                    left++;
                    while(left<right && nums[right]==r)
                    right--;
                }               
                else if(sum<target)
                {
                    
                    left++;
                }
                else
                {
                    
                    right--;
                }
            }
        }
        // auto new_end=unique(res.begin(),res.end());
        // res.erase(new_end,res.end());
        return res;                            
    }
};