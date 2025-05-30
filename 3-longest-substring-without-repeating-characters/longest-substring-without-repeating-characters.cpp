class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> hash;
        int n=s.size();
        if(n==0)
            return 0;
        int l=0,r=1,maxlen=1;
        hash[s[0]]=1;
        while(r<n){
            if(!hash[s[r]])
            {
                hash[s[r]]++;
                maxlen=max(maxlen,r-l+1);
            }
            else{
                while(hash[s[r]])
                    {
                        hash[s[l]]--;
                        l++;
                    }
                hash[s[r]]++;
            }
            r++;
        }
        return maxlen;
    }
};