class Solution {
public:
    string helper(int l, int r, string s) {
        int n = s.size();
        while (l >= 0 && r < n && s[l] == s[r]) {
            l--;
            r++;
        }
        // When the loop breaks, l and r have gone 1 step too far
        return s.substr(l + 1, r - l - 1);
    }

    string longestPalindrome(string s) {
        string res = "";
        for (int i = 0; i < s.size(); i++) {
            // Odd length
            string odd = helper(i, i, s);
            if (odd.size() > res.size()) res = odd;

            // Even length
            string even = helper(i, i + 1, s);
            if (even.size() > res.size()) res = even;
        }
        return res;
    }
};
