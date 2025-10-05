class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //x-k,k method prefix sum map
        unordered_map<long long,int> prefix;
        prefix[0]=1;
        int n=nums.size(),cnt=0;
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            long long rem=sum-k;
            if(prefix[rem])
            cnt+=prefix[rem];

            prefix[sum]++;
        }
        return cnt;
    }
};