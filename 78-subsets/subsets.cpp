class Solution {
public:
    vector<vector<int>> ans;
    void f(int i,vector<int> &subset,vector<int>& nums)
    {
        if(i<0)
        {
            ans.push_back(subset);
            return;
        }
        //pick
        subset.push_back(nums[i]);
        f(i-1,subset,nums);
        subset.pop_back();

        //not pick
        f(i-1,subset,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<int> subset;
        f(n-1,subset,nums);
        return ans;
    }
};