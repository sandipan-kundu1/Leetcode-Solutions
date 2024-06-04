class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle overflow case
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        // Determine the sign of the result
        bool sign = (dividend >= 0) == (divisor >= 0);

        // Convert to long to handle overflow and take absolute values
        long n = labs(dividend);
        long d = labs(divisor);
        long ans = 0;

        // Perform the division using bit manipulation
        while (n >= d) {
            long temp = d, multiple = 1;
            while (n >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            n -= temp;
            ans += multiple;
        }

        // Apply the sign to the result
        ans = sign ? ans : -ans;

        // Check for overflow and return the result
        if (ans > INT_MAX) {
            return INT_MAX;
        }
        if (ans < INT_MIN) {
            return INT_MIN;
        }
        return static_cast<int>(ans);
    }
};
