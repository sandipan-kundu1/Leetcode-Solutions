class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), cnt = 0, sum = 0;
        unordered_map<int, int> hash;
        hash[0] = 1; // There is one way to have a sum of 0, which is having no elements.

        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            if (hash.find(sum - k) != hash.end()) {
                cnt += hash[sum - k];
            }
            hash[sum]++;
        }
        return cnt;
    }
};