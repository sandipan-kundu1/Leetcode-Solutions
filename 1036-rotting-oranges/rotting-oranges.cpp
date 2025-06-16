class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n));
        int time=0;
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> dir{{0,1},{0,-1},{1,0},{-1,0}};
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                vis[i][j]=grid[i][j];
                if(grid[i][j]==2)
                q.push({{i,j},time});
            }
        }
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            time=p.second;
            auto coor=p.first;
            for(auto d:dir)
            {
                int ni=coor.first+d[0],nj=coor.second+d[1];
                if(ni>=0 && ni<m && nj>=0 && nj<n && vis[ni][nj]==1)
                {
                    vis[ni][nj]=2;
                    q.push({{ni,nj},time+1});
                    
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(vis[i][j]==1)
                return -1;
            }
        }
        return time;
    }
};