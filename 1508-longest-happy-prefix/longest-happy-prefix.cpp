class Solution {
public:
    string longestPrefix(string s) {
        int n=s.size();
        vector<int> lps(n,0);
        int i=1,prevlps=0;
        while(i<n)
        {
            if(s[i]==s[prevlps])
            {
                lps[i]=prevlps+1;
                prevlps++;
                i++;
            }
            else if(prevlps==0)
            {
                lps[i]=0;
                i++;
            }
            else
            prevlps=lps[prevlps-1];
        }

        return s.substr(0,lps[n-1]);
    }
};