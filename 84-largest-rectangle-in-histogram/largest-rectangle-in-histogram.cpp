class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        int n=height.size();
        vector<int> nse(n,n),pse(n,-1);
        stack<int> s,s1;
        for(int i=0;i<n;i++)
        {
            while(!s.empty() && height[s.top()]>=height[i])
            s.pop();
            if(!s.empty())  pse[i]=s.top();
            s.push(i);
        }
        for(int i=n-1;i>=0;i--)
        {
            while(!s1.empty() && height[s1.top()]>=height[i])
            s1.pop();
            if(!s1.empty())  nse[i]=s1.top();
            s1.push(i);
        }
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,(nse[i]-pse[i]-1)*height[i]);
        }
        return maxi;
    }
};