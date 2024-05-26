class Solution {
public:
    void sortColors(vector<int>& nums) {
        // int low = 0, mid = 0,
        //     high = nums.size() - 1; // dutch national flag algorithm
        // while (mid <= high) {
        //     if (nums[mid] == 0) {
        //         swap(nums[low], nums[mid]);
        //         low++;
        //         mid++;
        //     } else if (nums[mid] == 1)
        //         mid++;
        //     else {
        //         swap(nums[mid], nums[high]);
        //         high--;
        //     }
        // }

        int cnt0=0,cnt1=0,cnt2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)
            cnt0++;
            else if(nums[i]==1)
            cnt1++;
            else
            cnt2++;
        }
        for(int i=0;i<cnt0;i++)
            nums[i]=0;
        for(int i=0;i<cnt1;i++)
            nums[i+cnt0]=1;
        for(int i=0;i<cnt2;i++)
            nums[i+cnt0+cnt1]=2;
    }
};