class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        int low=0,high=m-1;
        while(low<=high){
            int mid=(low+high)/2;
            int maxind=findmax(mat,mid,n);
            int left= (mid>0) ? mat[maxind][mid-1] : -1;
            int right=(mid<m-1) ? mat[maxind][mid+1] : -1;
            if(mat[maxind][mid]>left && mat[maxind][mid]>right)
            return {maxind, mid};
            else if(mat[maxind][mid]<left)
            high=mid-1;
            else
            low=mid+1;
        }
        return {-1 , -1};
    }
    public:
    int findmax(vector<vector<int>>& mat, int col, int n){
        int maxind=0;
        for(int i=0;i<n;i++){
            if(mat[i][col]> mat[maxind][col])
            maxind=i;
        }
        return maxind;
    }
};