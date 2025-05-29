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
                    fr+='#'+to_string(freq[i]);
                hash[fr].push_back(s);
            }
        vector<vector<string>> res;
        for(auto i:hash)
            res.push_back(i.second);
        return res;
    }
};