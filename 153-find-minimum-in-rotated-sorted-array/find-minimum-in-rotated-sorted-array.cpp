class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0,high=nums.size()-1,ans=INT_MAX;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(low==high){
                ans=min(ans,nums[low]);
                break;
            }
                
            //checking sorted half, as min pivot point(mostly not except mid=pivot) may or may not lie in sorted half so carrying its minimum
                
            //left half sorted
            else if(nums[low]<=nums[mid])
            {
                ans=min(ans,nums[low]);
                low=mid+1;
            }
            //right half sorted
            else{
                ans=min(ans,nums[mid]);
                high=mid-1;
            } 
        }
        return ans;
    }
};