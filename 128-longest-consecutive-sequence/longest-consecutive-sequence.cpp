class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return 0;
        unordered_set<int> hash;
        for(int i=0;i<n;i++)
            hash.insert(nums[i]);
        int maxlen=1,len=1;
        for(int i:hash)
            {
                if(hash.find(i-1)==hash.end())
                {
                    int start=i,len=1;
                    while(hash.find(start+1)!=hash.end())
                        {
                            start++;
                            len++;
                        }
                    maxlen=max(maxlen,len);
                }
            }
        return maxlen;
    }
};