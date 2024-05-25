class Solution {
public:
    void findsubset(int ind, vector<int>& arr, vector<int>& ds,
                    vector<vector<int>>& ans) {
        ans.push_back(ds);

        for (int i = ind; i < arr.size(); i++) {
            if (i > ind && arr[i] == arr[i - 1])
                continue;
            ds.push_back(arr[i]);
            findsubset(i + 1, arr, ds, ans);
            ds.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> ds;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        findsubset(0, nums, ds, ans);
        return ans;
    }
};