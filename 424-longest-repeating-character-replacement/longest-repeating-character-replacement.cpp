class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int l=0,r=0,maxf=0,changes,maxlen=0;
        unordered_map<char,int> hash;
        while(r<n){
            hash[s[r]]++;
            maxf=max(maxf,hash[s[r]]);
            changes=r-l+1 - maxf;
            while(changes>k){
                hash[s[l]]--;
                l++;
                for(auto it:hash)
                    maxf=max(maxf,it.second);
                changes=r-l+1-maxf;
            }
            if(changes<=k)
                maxlen=r-l+1;
            r++;
        }
        return maxlen;
    }
};