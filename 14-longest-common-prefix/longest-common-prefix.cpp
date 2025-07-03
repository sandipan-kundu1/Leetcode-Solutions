class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string common="";
        sort(strs.begin(),strs.end());
        string mini=strs[0];
        for(int i=0;i<mini.size();i++)
        {
            char c=mini[i];
            for(int j=1;j<strs.size();j++)
            {
                if(i>=strs[j].size() || strs[j][i]!=c)
                return common;
            }
            common+=c;
        }
        return common;
    }
};