class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n == 0) return 0;
        
        vector<int> left(n, 1); // Each child must get at least one candy
        
        // Left to right pass
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                left[i] = left[i - 1] + 1;
            }
        }
        
        int candies = left[n - 1]; // Initialize candies with the last child's candy count
        
        // Right to left pass
        for (int i = n - 2; i >= 0; i--) {
            int right = 1;
            if (ratings[i] > ratings[i + 1]) {
                right = left[i + 1] + 1;
            }
            candies += max(left[i], right);
            left[i] = max(left[i], right); // Update left[i] to ensure it holds the max candies needed
        }
        
        return candies;
    }
};
