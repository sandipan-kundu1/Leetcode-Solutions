class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xorr = 0;
        for (int i = 0; i < nums.size(); i++) {
            xorr = xorr ^ nums[i];
        }
        return xorr;
        // map<int, int> mpp;
        // for(int i = 0; i < nums.size(); i++) {
        //     mpp[nums[i]]++;
        // }
        // for(auto it : mpp) {
        //     if(it.second == 1)
        //         return it.first;
        // }
        // return -1;
        // int maxi = nums[0];
        // int n = nums.size();

        // for (int i = 1; i < n; i++) {
        //     maxi = max(maxi, nums[i]);
        // }

        // vector<int> hash(maxi + 1, 0);

        // for (int i = 0; i < n; i++) {
        //     hash[nums[i]]++;
        // }

        // for (int i = 0; i < n; i++) {
        //     if (hash[nums[i]] == 1) {
        //         return nums[i];
        //     }
        // }

        // return -1;
    }
};