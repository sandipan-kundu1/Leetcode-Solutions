class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int first = -1, last = -1;
        
        auto it = lower_bound(nums.begin(), nums.end(), target);
        
        // Check if the element is present
        if (it == nums.end() || *it != target) {
            return {-1, -1};
        }
        
        first = it - nums.begin();
        last = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
        
        return {first, last};
    }
};