class Solution {
public:
    int search(vector<int>& nums, int target) {
        return binsearch(0, nums.size() - 1, nums, target);
    }

public:
    int binsearch(int low, int high, vector<int>& nums, int target) {
        int mid;
        mid = low + (high - low) / 2;
        if(low>high)
        return -1;
        else if(nums[mid] == target)
            return mid;
        else if (nums[mid] > target)
        return binsearch(low,mid-1,nums,target);
        else 
        return binsearch(mid+1, high, nums, target);
    }
};