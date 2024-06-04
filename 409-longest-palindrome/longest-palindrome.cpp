class Solution {
public:
    int longestPalindrome(string s) {
        if (s.length() == 1)
            return 1;
        
        int longest = 0;
        bool flag = false;
        map<char, int> mpp;

        for (char c : s) {
            mpp[c]++;
        }

        for (auto i : mpp) {
            if (i.second % 2 == 0)
                longest += i.second;
            else {
                longest += i.second - 1;
                flag = true;
            }
        }

        if (flag)
            longest += 1;

        return longest;
    }
};