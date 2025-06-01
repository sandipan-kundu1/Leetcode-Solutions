class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for(char c:s){
            if(c=='(' || c=='{' || c=='[')
                st.push(c);
            else{
                if(st.empty())
                    return false;
                int top=st.top();
                if(c==')' && top=='(')
                    st.pop();
                else if(c=='}' && top=='{')
                    st.pop();
                else if(c==']' && top=='[')
                    st.pop();
                else 
                    return false;
            }
        }
        if(st.empty())
            return true;
        return false;
    }
};