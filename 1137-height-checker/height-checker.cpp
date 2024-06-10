class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> given;
        for(int i=0;i<heights.size();i++){
            given.push_back(heights[i]);
        }
        sort(heights.begin(),heights.end());
        int cnt=0;
        for(int i=0;i<heights.size();i++){
            if(heights[i]!=given[i])
            cnt++;
        }
        return cnt;
    }
};