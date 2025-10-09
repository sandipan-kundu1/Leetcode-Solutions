class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=0,n=nums.size(),el,cnt1=0;
        for(int i=0;i<n;i++)
        {
            if(cnt==0)
            {
                el=nums[i];
                cnt++;
            }
            else if(el==nums[i])
            cnt++;
            else
            cnt--;
        }
        for(int i=0;i<n;i++)
        if(nums[i]==el)
        cnt1++;
        if(cnt1>n/2)
        return el;
        return -1;
    }
};