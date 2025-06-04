class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row=matrix.size(),col=matrix[0].size();
        unordered_set<int> rows,cols;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]==0)
                    {
                        rows.insert(i);
                        cols.insert(j);
                    }    
            }
        }

        for(int i:rows){
            for(int j=0;j<col;j++)
            matrix[i][j]=0;
        }
        for(int j:cols){
            for(int i=0;i<row;i++)
                matrix[i][j]=0;
        }
        
    }
};