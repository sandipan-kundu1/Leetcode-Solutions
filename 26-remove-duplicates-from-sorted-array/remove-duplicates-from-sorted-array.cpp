class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        auto it = unique(nums.begin(), nums.end());
        nums.resize(it-nums.begin());
        return nums.size();
    }
};
