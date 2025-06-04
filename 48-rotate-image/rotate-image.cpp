class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        //Rotate 90= transpose+ reverse each row
        //Rotate 180= reverse each row+ reverse order of rows
        //Rotate 270= transpose+ reverse each col
        
        for(int row=0;row<n;row++)
            for(int col=row+1;col<n;col++)
                swap(matrix[row][col],matrix[col][row]);

        for(int i=0;i<n;i++)
            reverse(matrix[i].begin(),matrix[i].end());
        
    }
};