class Solution {
public:
int m,n;
vector<vector<int>> dir{{0,1},{1,0},{0,-1},{-1,0}};
    void dfs(int r,int c,vector<vector<int>>& heights,vector<vector<int>>& curr)
    {
        curr[r][c]=1;
        for(auto d:dir)
        {
            int nr=r+d[0];
            int nc=c+d[1];
            if(nr>=0 && nr<m && nc>=0 && nc<n && !curr[nr][nc] && heights[nr][nc]>=heights[r][c])
            dfs(nr,nc,heights,curr);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m=heights.size();
        n=heights[0].size();
        vector<vector<int>> res;
        vector<vector<int>> pac(m,vector<int>(n,0)), atl(m,vector<int>(n,0));
        
        for(int j=0;j<n;j++)  dfs(0,j,heights,pac);     //top
        for(int i=0;i<m;i++)  dfs(i,0,heights,pac);     //left
        for(int i=0;i<m;i++)  dfs(i,n-1,heights,atl);   //right
        for(int j=0;j<n;j++)  dfs(m-1,j,heights,atl);   //down

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(pac[i][j] && atl[i][j])
                res.push_back({i,j});
            }
        }
        return res;
    }
};