class Solution {
public:
    string compressedString(string word) {
        if (word.empty()) return "";  // Edge case: empty string

        int i = 1, len = 1;
        char j = word[0];
        string comp = "";

        while (i < word.size()) {
            if (word[i] == j && len < 9) {
                len++;
            } else {
                comp += to_string(len) + j;  // Concatenate length and character
                j = word[i];
                len = 1;
            }
            i++;
        }
        comp += to_string(len) + j;  // Append the last sequence

        return comp;
    }
};