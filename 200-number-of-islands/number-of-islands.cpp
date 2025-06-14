class Solution {
public:
    void dfs(int i,int j,vector<vector<int>> &vis,vector<vector<char>>& grid)
    {
        vis[i][j]=1;
        int m=grid.size(),n=grid[0].size();
        if(i<m-1 &&  grid[i+1][j]=='1' && !vis[i+1][j])  dfs(i+1,j,vis,grid);
        if(i>0 && grid[i-1][j]=='1' && !vis[i-1][j])    dfs(i-1,j,vis,grid);
        if(j<n-1 && grid[i][j+1]=='1' && !vis[i][j+1])  dfs(i,j+1,vis,grid);
        if(j>0 && grid[i][j-1]=='1' && !vis[i][j-1])    dfs(i,j-1,vis,grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int cnt=0;
        vector<vector<int>> vis(m,vector<int>(n,0));
        //find number of components of graph
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1' && !vis[i][j])
                {
                    dfs(i,j,vis,grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};