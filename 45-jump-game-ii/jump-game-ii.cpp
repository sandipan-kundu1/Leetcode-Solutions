class Solution {
public:
    int jump(vector<int>& nums) {
        int l = 0, r = 0, jumps = 0;

        while (r < nums.size() - 1) {
            int farthest = 0;
            for (int i = l; i <= r; i++)
                farthest = max(farthest, i + nums[i]);
            l = r;
            r = farthest;
            jumps++;
        }

        return jumps;
    }
};