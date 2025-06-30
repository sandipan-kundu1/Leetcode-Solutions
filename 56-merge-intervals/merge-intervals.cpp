class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> merged;
        sort(intervals.begin(),intervals.end(), [](vector<int>&a,vector<int>&b){
            return a[0]<b[0];
        });

        int time=-1,prevstart=-1;
        for(auto &p:intervals)
        {
            int start=p[0],end=p[1];

            if(start>time)
            {
                if(prevstart!=-1)
                merged.push_back({prevstart,time});
                prevstart=start;
            }
            time=max(time,end);
        }
        merged.push_back({prevstart,time});
        return merged;
    }
};