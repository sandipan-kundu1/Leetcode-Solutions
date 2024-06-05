class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        // Initialize the frequency map with a high count for each character
        vector<int> minFreq(26, INT_MAX);
        
        // Iterate over each word to update the minimum frequency of each character
        for (const string& word : words) {
            vector<int> charCount(26, 0);
            for (char c : word) {
                charCount[c - 'a']++;
            }
            for (int i = 0; i < 26; ++i) {
                minFreq[i] = min(minFreq[i], charCount[i]);
            }
        }
        
        // Collect the common characters
        vector<string> ans;
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < minFreq[i]; ++j) {
                ans.push_back(string(1, i + 'a'));
            }
        }
        
        return ans;
    }
};
