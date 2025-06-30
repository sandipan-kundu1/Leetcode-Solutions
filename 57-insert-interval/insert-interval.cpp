class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int newstart=newInterval[0],newend=newInterval[1];
        int i=0,n=intervals.size();
        vector<vector<int>> res;
        while(i<n && intervals[i][1]<newstart)
        {
            res.push_back(intervals[i]);
            i++;
        }
        //main position of insertion
        while(i<n && newInterval[1]>=intervals[i][0])
        {
            newstart=min(newstart,intervals[i][0]);
            newend=max(newend,intervals[i][1]);
            i++;
        }
        res.push_back({newstart,newend});

        while(i<n)
        {
            res.push_back(intervals[i]);
            i++;
        }
        return res;
    }
};