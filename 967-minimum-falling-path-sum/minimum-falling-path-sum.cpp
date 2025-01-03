class Solution {
public:
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<int> prev(n);
        vector<int> cur(n);

        for(int j=0;j<n;j++)
        prev[j]=matrix[0][j];
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int up=1e8,ld=1e8,rd=1e8;
                up=matrix[i][j]+ prev[j];
                if(j>0) ld=matrix[i][j]+ prev[j-1];
                if(j<n-1) rd=matrix[i][j]+ prev[j+1];
                cur[j]=min({up,ld,rd});
            }
            prev=cur;
        }
        int mini=prev[0];
        for(int j=1;j<n;j++)
        mini=min(mini, prev[j]);
        return mini;
    }
};