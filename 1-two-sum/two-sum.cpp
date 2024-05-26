class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Hashmap approach(better)   for brute force nested loop case
        map<int, int> mpp;
        for (int i = 0; i < nums.size(); i++) {
            int more = target - nums[i];

            if (mpp.find(more) != mpp.end()) {

                return {mpp[more], i};
            }
            mpp[nums[i]] = i;
        }
        // return ans;
        return {-1, -1};
    }
};