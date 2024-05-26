class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //Hashmap approach(better)   for brute force nested loop case
        map<int, int> mpp;
        int i=0;
        // vector<int> ans;
        while(i<nums.size()){
            int more=target-nums[i];
            
            if(mpp.find(more)!=mpp.end())
            {
                // ans.push_back(mpp[more]);
                // ans.push_back(i);
                return {mpp[more],i};
            }
            mpp[nums[i]]=i;
            i++;
        }
        // return ans;
        return {-1,-1};
    }
};