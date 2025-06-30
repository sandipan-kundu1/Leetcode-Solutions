class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),[](vector<int>& a,vector<int>& b){
            return a[1]>b[1];
        });
        int maxunits=0;
        for(auto box:boxTypes)
        {
            if(box[0]<=truckSize)
            {
                maxunits+=box[0]*box[1];
                truckSize-=box[0];
            }
            else
            {
                maxunits+=truckSize*box[1];
                truckSize=0;
            }
        }
        return maxunits;
    }
};