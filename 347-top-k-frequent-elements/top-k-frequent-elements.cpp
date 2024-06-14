class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> hash;
        for(int i:nums)
        hash[i]++;
        typedef pair<int,int> p;
        priority_queue<p, vector<p>, greater<p>> minheap;
        for(auto i:hash){
            minheap.push({i.second, i.first});
            if(minheap.size()>k)
            minheap.pop();
        }
        vector<int> v;
        while(minheap.size()){
            v.push_back(minheap.top().second);
            minheap.pop();
        }
        return v;
    }
};