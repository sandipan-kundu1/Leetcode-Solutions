class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size(),m=strs[0].size();
        vector<string> temp=strs;
        for(auto &i:temp)
            sort(i.begin(),i.end());
        vector<vector<string>> res;
        unordered_map<string,vector<string>> hash;

        for(int i=0;i<n;i++)
            {
                hash[temp[i]].push_back(strs[i]);
            }
        for(auto s:hash)
            res.push_back(s.second);
        return res;
    }
};