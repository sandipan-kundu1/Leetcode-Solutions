class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target)
                return true;
            //3 1 2 3 3 3 3 this case both side looks sorted, depicts tar 1 don't lie any of these
            else if(nums[low]==nums[mid] && nums[mid]==nums[high])
            {
                low++;
                high--;
            }
            else if(nums[low]<=nums[mid]){
                if(nums[low]<=target && target<nums[mid])
                    high=mid-1;
                else
                    low=mid+1;
            }
            else{
                if(nums[mid]<target && target<=nums[high])
                    low=mid+1;
                else 
                    high=mid-1;
            }
        }
        return false;
    }
};