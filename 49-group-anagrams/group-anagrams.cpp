class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size(),m=strs[0].size();
        unordered_map<string,vector<string>> hash;
        for(auto &s:strs)
            {
                vector<int> freq(26,0);
                for(char c:s)
                    freq[c-'a']++;
                string fr;
                for(int i=0;i<26;i++)
                    fr+='#'+to_string(freq[i]); //# used to differentiate each characters count e.g. 1b 10d , 10b, 1c  both forms 01010000.. same string.
                hash[fr].push_back(s);
            }
        vector<vector<string>> res;
        for(auto i:hash)
            res.push_back(i.second);
        return res;
    }
};