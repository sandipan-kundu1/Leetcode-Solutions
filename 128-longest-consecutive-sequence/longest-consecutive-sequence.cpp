class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        int cnt,longest=0;
        for(auto i:nums)
        st.insert(i);
        for(auto it:st){
            if(st.find(it-1)==st.end()){
                int cnt=0;
                int x=it;
                while(st.find(x)!=st.end()){
                    x++;
                    cnt++;
                }
                longest=max(longest,cnt);
            }
            
        }
        return longest;
        // sort(nums.begin(),nums.end());
        // int lastsmaller=INT_MIN;
        // int cnt=0,longest=0;
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]-1==lastsmaller)
        //     {
        //         cnt+=1;
        //         lastsmaller=nums[i];
        //     }
        //     else if(nums[i]!=lastsmaller){
                
        //         cnt=1;
        //         lastsmaller=nums[i];
        //     }
        //     longest=max(longest,cnt);
        // }
        // return longest;
    }
};