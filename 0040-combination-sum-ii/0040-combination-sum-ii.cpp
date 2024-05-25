class Solution {
public:
    void findcombination(int ind, int target, vector<int>& arr, vector<int>& ds,
                         vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(ds);
            return;
        }

        for (int i = ind; i < arr.size(); i++) {
            if (arr[i] > target)
                break;
            if (i > ind && arr[i] == arr[i - 1])
                continue;
            ds.push_back(arr[i]);
            findcombination(i + 1, target - arr[i], arr, ds, ans);
            ds.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> ds;
        vector<vector<int>> ans;
        sort(candidates.begin(),candidates.end());
        findcombination(0, target, candidates, ds, ans);
        return ans;
    }
};