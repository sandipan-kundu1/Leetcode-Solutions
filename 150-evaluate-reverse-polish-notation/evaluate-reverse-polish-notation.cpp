class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int ans;
        unordered_set<string> op;
        op.insert("+");
        op.insert("-");
        op.insert("/");
        op.insert("*");
        for(auto it:tokens)
        {
            if(op.find(it)!=op.end())
            {
                int op2=s.top();
                s.pop();
                int op1=s.top();
                s.pop();
                int res;
                if(it=="+") res=op1+op2;
                if(it=="-") res=op1-op2;
                if(it=="*") res=op1*op2;
                if(it=="/") res=op1/op2;
                s.push(res);
            }
            else
            {
                s.push(stoi(it));
            }
        }
        return s.top();
    }
};