class Solution {
    public:
    long long func(int k, vector<int>& piles) {
        long long total = 0;
        for (int i = 0; i < piles.size(); i++) {
            total += ceil(double(piles[i]) / double(k));
        }
        return total;
    }
    
    public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // Binary search TC: O(n * log2(maxel))
        int low = 1, high = *max_element(piles.begin(), piles.end()), mid;
        while (low <= high) {
            mid = (low + high) / 2;
            long long totalh = func(mid, piles);
            if (totalh <= h) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};
