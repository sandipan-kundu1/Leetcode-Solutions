class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
            return false;
        unordered_map<int,int> hash;
        for(int i=0;i<s.size();i++)
            {
                hash[s[i]]++;
            }
        for(int i=0;i<t.size();i++)
            {
                hash[t[i]]--;
                if(hash[t[i]]==0)
                    hash.erase(t[i]);
            }
        if(hash.size()==0)
        return true;
        return false;
    }
};