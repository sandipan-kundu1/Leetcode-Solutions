class Solution {
public:
    void findcombination(int ind, int target, vector<int>& arr, vector<int>& ds,
                         vector<vector<int>>& ans) {
        if (ind == arr.size()) {
            if (target == 0)
                ans.push_back(ds);
            return;
        }
        if (arr[ind] <= target) {
            ds.push_back(arr[ind]);
            findcombination(ind, target - arr[ind], arr, ds, ans);
            ds.pop_back();
        }
        findcombination(ind + 1, target, arr, ds, ans);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ds;
        vector<vector<int>> ans;
        findcombination(0, target, candidates, ds, ans);
        return ans;
    }
};