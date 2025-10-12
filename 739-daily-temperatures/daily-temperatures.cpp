class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n=t.size();
        vector<int> ans(n,0);
        stack<pair<int,int>> s;
        //s.push(1e8);
        for(int i=n-1;i>=0;i--)
        {
            while(!s.empty() && s.top().first<=t[i])
            s.pop();
            if(!s.empty()) 
            ans[i]=s.top().second-i;
            s.push({t[i],i});
        }
        return ans;
    }
};