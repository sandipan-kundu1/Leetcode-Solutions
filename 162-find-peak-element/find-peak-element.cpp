class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        
        // Edge case: single element
        if (n == 1)
            return 0;
        
        // Check if the first or last elements are peak elements
        if (nums[0] > nums[1])
            return 0;
        if (nums[n-1] > nums[n-2])
            return n-1;

        // Binary search in the range [1, n-2]
        int low = 1, high = n-2;
        while (low <= high) {
            int mid = (low + high) / 2;
            
            // Check if mid element is a peak
            if (nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1])
                return mid;
            
            // If mid element is part of an increasing sequence, move right
            if (nums[mid-1] < nums[mid])
                low = mid + 1;
            // If mid element is part of a decreasing sequence, move left
            else if (nums[mid] > nums[mid+1])
                high = mid - 1;
            else if(nums[mid]<nums[mid-1] && nums[mid]<nums[mid+1])
                low=mid+1;
        }
        
        // The loop should always return a peak element within the constraints
        return -1;

        // for(int i=0;i<n;i++){
        //     if((i==0 || nums[i]>nums[i-1]) && (i==n-1 || nums[i]>nums[i+1]))
        //     return i;
        // }
        // return -1;
    }
};