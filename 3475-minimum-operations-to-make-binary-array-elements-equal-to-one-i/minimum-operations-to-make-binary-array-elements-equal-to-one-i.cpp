class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int op = 0;

        for (int i = 0; i <= n - 3; ++i) {
            if (nums[i] == 0) {
                // Perform the flip operation on nums[i], nums[i+1], nums[i+2]
                nums[i] ^= 1;
                nums[i + 1] ^= 1;
                nums[i + 2] ^= 1;
                ++op;
            }
        }

        // Check if the last two elements are still zeros
        if (nums[n - 2] == 0 || nums[n - 1] == 0) {
            return -1;
        }

        return op;
    }
};
