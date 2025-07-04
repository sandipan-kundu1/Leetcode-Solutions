class Solution {
public:
    bool row(int i,vector<vector<char>>& board)
    {
        vector<int> vis(10,0);
        for(int col=0;col<9;col++)
        {
            if(board[i][col]!='.' && !vis[board[i][col]-'0'])
            {
                vis[board[i][col]-'0']=1;
            }
            else if(board[i][col]!='.')
            return false; 
        }
        return true;
    }
    bool col(int j,vector<vector<char>>& board)
    {
        vector<int> vis(10,0);
        for(int row=0;row<9;row++)
        {
            if(board[row][j]!='.' && !vis[board[row][j]-'0'])
            vis[board[row][j]-'0']=1;
            else if(board[row][j]!='.')
            return false;
        }
        return true;
    }
    bool subbox(int i,int j,vector<vector<char>>& board)
    {
        vector<int> vis(10,0);
        for(int row=i;row<i+3;row++)
        {
            for(int col=j;col<j+3;col++)
            {
                if(board[row][col]!='.' && !vis[board[row][col]-'0'])
                vis[board[row][col]-'0']=1;
                else if(board[row][col]!='.')
                return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        //row check
        for(int i=0;i<9;i++)
        {
            if(!row(i,board))
            return false;
        }
        //col check
        for(int j=0;j<9;j++)
        {
            if(!col(j,board))
            return false;
        }
        //subbox check
        for(int i=0;i<9;i=i+3)
        {
            for(int j=0;j<9;j=j+3)
            {
                if(!subbox(i,j,board))
                return false;
            }
        }
        return true;
    }
};