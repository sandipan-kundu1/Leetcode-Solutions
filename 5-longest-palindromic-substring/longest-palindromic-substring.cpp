class Solution {
public:
    string helper(int l,int r,string s)
    {
        int n=s.size();
        string res="";
        int reslen=0;
        while(l>=0 && r<n && s[l]==s[r])
            {
                if(r-l+1>reslen)
                {
                    reslen=r-l+1;
                    res=s.substr(l,r-l+1); //substr(starting index, length of substring)
                }
                l--;
                r++;
            }
        
        
        return res;
    }
    string longestPalindrome(string s) {
        int n=s.size();
        string res="";
        for(int i=0;i<n;i++)
        {
            string odd=helper(i,i,s);
            if(res.size()<odd.size())
            res=odd;
            string even=helper(i,i+1,s);
            if(res.size()<even.size())
            res=even;
        }
        return res;

    }
};