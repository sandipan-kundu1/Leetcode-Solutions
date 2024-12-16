class Solution {
    void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<int>>& vis)
    {
        vis[i][j]=1;
        int n = grid.size();
        int m = grid[0].size();
        int directions[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        for(int k = 0; k < 4; k++)
        {
            int x = i + directions[k][0];
            int y = j + directions[k][1];
            if(x>=0 && x<n && y>=0 && y<m && grid[x][y]=='1' && vis[x][y]==0)
            {
                dfs(x,y,grid,vis);
                
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1' && !vis[i][j])
                {
                    count++;
                    dfs(i,j,grid,vis);
                }
            }
        }
        return count;
    }
};