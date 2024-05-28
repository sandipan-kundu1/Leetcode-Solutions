class Solution {
public:
    void setrow(int k, vector<vector<int>>& matrix, int n) {
        for (int j = 0; j < n; j++)
        {
            if(matrix[k][j]!=0)
                matrix[k][j] = -1;
        }
            
    }

public:
    void setcol(int k, vector<vector<int>>& matrix, int m) {
        for (int i = 0; i < m; i++){
            if(matrix[i][k]!=0)
                matrix[i][k] = -1;
        }
            
    }

public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> col(n,0);
        vector<int> row(m,0);   //better TC:O(m*n)   SC:O(m+n)
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    row[i]=1;
                    col[j]=1;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(row[i] || col[j]){
                    matrix[i][j]=0;
                }
            }
        }
        
        // for (int i = 0; i < m; i++) {
        //     for (int j = 0; j < n; j++) {
                
        //         if (matrix[i][j] == 0) {
        //             setrow(i, matrix, n);
        //             setcol(j, matrix, m);    brute force: TC: O(m*n*(m+n))   SC:O(1)
        //         }
        //     }
        // }
        // for (int i = 0; i < m; i++) {
        //     for (int j = 0; j < n; j++) {
        //         if (matrix[i][j] == -1) {
        //             matrix[i][j] = 0;
        //         }
        //     }
        // }
        
    }
};