class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(),m=matrix[0].size();
        int low=0,high=m*n-1;
        while(low<=high){
            int mid=(low+high)/2;
            int rowmid=mid/m,colmid=mid%m;
            if(matrix[rowmid][colmid]==target)
            return true;
            else if(matrix[rowmid][colmid]>target)
            high=mid-1;
            else
            low=mid+1;
        }
        return false;
    }
};