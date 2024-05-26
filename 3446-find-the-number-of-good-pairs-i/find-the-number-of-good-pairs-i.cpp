class Solution {
public:
    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int j=0,i=0,cnt=0;
        while(i<nums1.size()){
            if(j==nums2.size())
            {
                i++;
                j=0;
            }
            else{
                if(nums1[i]%(nums2[j]*k)==0)
                    cnt++;
                j++;
            }
        }
        return cnt; 
    }
};