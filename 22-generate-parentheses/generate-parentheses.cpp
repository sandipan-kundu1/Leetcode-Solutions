class Solution {
public:
    void f(int open,int close,string& s,vector<string> &res,int n)
    {
        if(open==n && close==n)
        {
            res.push_back(s);
            return;
        }
        if(open<n)
        {
            s.push_back('(');
            f(open+1,close,s,res,n);
            s.pop_back();
        }
        if(close<open)
        {
            s.push_back(')');
            f(open,close+1,s,res,n);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s;
        f(0,0,s,res,n);
        return res;
    }
};