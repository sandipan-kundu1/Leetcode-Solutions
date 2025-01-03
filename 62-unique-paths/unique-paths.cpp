class Solution {
public:
    int uniquePaths(int m, int n) {
        //topdown approach will be from [m-1][n-1] to [0][0] so moves up and left
        
        vector<int> prev(n);
        for(int i=0;i<m;i++)
        {
            vector<int> cur(n);
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0)
                cur[j]=1;
                else
                {
                    int up=0,left=0;
                    if(i>0) up=prev[j];
                    if(j>0) left=cur[j-1];
                    cur[j]=up+left;
                }
                
            }
            prev=cur;
        }
        return prev[n-1];
    }
};