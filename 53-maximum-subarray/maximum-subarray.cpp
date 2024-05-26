class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //Kadane's Algorithm
        int sum=0,maxi=INT_MIN;
        // int start,astart,aend;
        for(int i=0;i<nums.size();i++){
            if(sum<0){
                sum=0;
                // start=i;
            }
            sum+=nums[i];
            if(sum>maxi){
                maxi=sum;
                // astart=start;
                // aend=i;
            }

        }
        return maxi;
    }
};