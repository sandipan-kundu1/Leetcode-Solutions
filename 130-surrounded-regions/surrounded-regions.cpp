class Solution {
public:
    void dfs(int i,int j,int n,int m,vector<vector<int>> &vis,vector<vector<char>>& board)
    {
        if(vis[i][j]==1)
        return;
        vis[i][j]=1;
        int x[] = {-1, 0, 1, 0};
        int y[] = {0, -1, 0, 1};
        for(int k=0;k<4;k++)
        {
            int nx=i+x[k];
            int ny=j+y[k];
            if(nx>=0 && nx<n && ny>=0 && ny<m && board[nx][ny]=='O' && !vis[nx][ny])
            dfs(nx,ny,n,m,vis,board);
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size(); //reverse n,m of given in qu statement
        int m=board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            if(board[i][0]=='O')
            dfs(i,0,n,m,vis,board);
            if(board[i][m-1]=='O')
            dfs(i,m-1,n,m,vis,board);
        }
        for(int j=1;j<m-1;j++)
        {
            if(board[0][j]=='O')
            dfs(0,j,n,m,vis,board);
            if(board[n-1][j]=='O')
            dfs(n-1,j,n,m,vis,board);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='O' && !vis[i][j])
                board[i][j]='X';
            }
        }
    }
};