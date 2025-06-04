class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<int> order;
        int n=matrix.size();
        for(int col=0;col<n;col++)
            for(int row=n-1;row>=0;row--)
                order.push_back(matrix[row][col]);
        int k=0;    
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                matrix[i][j]=order[k++];
    }
};