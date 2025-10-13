class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> v;
        int n=speed.size();
        for(int i=0;i<n;i++)
        {
            v.push_back({position[i],speed[i]});
        }
        sort(v.begin(),v.end(),[](pair<int,int>& a,pair<int,int>& b){
            return a.first>b.first;
        });
        stack<float> s;
        for(auto it:v)
        {
            float time=(float)(target-it.first)/(float)it.second;
            if(s.empty() || time>s.top())
            s.push(time);
        }
        return s.size();
    }
};