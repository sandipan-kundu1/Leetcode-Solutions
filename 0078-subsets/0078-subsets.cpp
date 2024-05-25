class Solution {
public:
    void findsubset(int ind, vector<int>& arr, vector<int>& ds,
                    vector<vector<int>>& ans) {
        if (ind == arr.size()) {
            ans.push_back(ds);
            return;
        }

        ds.push_back(arr[ind]);
        findsubset(ind + 1, arr, ds, ans);
        ds.pop_back();
        findsubset(ind + 1, arr, ds, ans);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ds;
        vector<vector<int>> ans;
        findsubset(0, nums, ds, ans);
        return ans;
    }
};