class Solution {
public:
    int subarraysDivByK(std::vector<int>& nums, int k) {
        // Map to store the frequency of remainders
        std::unordered_map<int, int> remainderFrequency;
        // Initialize the frequency of remainder 0 to 1
        remainderFrequency[0] = 1;
        
        int sum = 0, cnt = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            // Calculate remainder
            int remainder = sum % k;
            // Handle negative remainders
            if (remainder < 0) remainder += k;
            
            // If this remainder has been seen before, it means there are 
            // remainderFrequency[remainder] subarrays that can be formed
            // ending at the current index which are divisible by k
            if (remainderFrequency.find(remainder) != remainderFrequency.end()) {
                cnt += remainderFrequency[remainder];
            }
            
            // Increment the frequency of this remainder
            remainderFrequency[remainder]++;
        }
        
        return cnt;
    }
};