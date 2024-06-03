class Solution {

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ds;
        vector<vector<int>> ans;
        int n=nums.size(), subset=1<<n;
        for(int j=0;j<subset; j++){
            ds={};
            for(int i=0;i<n;i++){
                if(j & (1<<i)){
                    ds.push_back(nums[i]);
                }
            }
            ans.push_back(ds);
        }
        return ans;
    }
};