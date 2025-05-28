class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<pair<int,int>> v(n);
        for(int i=0;i<n;i++)
            {
                v[i].first=nums[i];
                v[i].second=i;
            }
        sort(v.begin(),v.end());
        int i=0,j=n-1;
        while(i<j)
            {
                int sum=v[i].first+v[j].first;
                if(sum==target)
                    break;
                else if(sum<target)
                    i++;
                else
                    j--;
            }
        return {v[i].second,v[j].second};
    }
};
