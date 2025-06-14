class Solution {
public:
    int helper(int l,int r,string s)
    {
        int n=s.size(),cnt=0;
        while(l>=0 && r<n && s[l]==s[r])
        {
            cnt++;
            l--;
            r++;
        }
        return cnt;
    }
    int countSubstrings(string s) {
        int n=s.size(),cnt=0;
        for(int i=0;i<n;i++)
        {
            int odd=helper(i,i,s);
            int even=helper(i,i+1,s);
            cnt+=odd+even;
        }
        return cnt;
    }
};