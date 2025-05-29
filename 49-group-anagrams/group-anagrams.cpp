class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size(),m=strs[0].size();
        vector<map<char,int>> freq(n);
        for(int i=0;i<n;i++)
            {
                for(auto c:strs[i])
                    freq[i][c]++;
            }
        vector<vector<string>> res;
        map<map<char,int>, vector<string>> mp;

        for(int i=0;i<freq.size();i++)
            {
                mp[freq[i]].push_back(strs[i]);
            }
        for(auto &it:mp)
            res.push_back(it.second);
        return res;
    }
};