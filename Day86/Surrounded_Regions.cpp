class Solution {
public:

    void dfs(int row, int col, vector<vector<char>> board, vector<vector<int>>& vis)
    {
        vis[row][col] = 1;

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        int n = board.size();
        int m = board[0].size();

        for(int i=0;i<4;i++)
        {
            int nrow = row + delrow[i];
            int ncol = col  + delcol[i];
            if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && board[nrow][ncol] == 'O' && !vis[nrow][ncol])
            {
                dfs(nrow, ncol, board, vis);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        
        int n = board.size();
        int m = board[0].size();

        //visited array
        vector<vector<int>> vis(n, vector<int>(m, 0));

        //making dfs calls to boundary items as they can't be converted
        //for first row and last row
        for(int j=0;j<m;j++)
        {   
            //first row dfs
            if(board[0][j] == 'O' && !vis[0][j])
            {
                dfs(0, j, board, vis);
            }
            //last row dfs
            if(board[n-1][j] == 'O' && !vis[n-1][j])
            {
                dfs(n-1, j, board, vis);
            }
        }

        //for last column and first column
        for(int i=0; i<n; i++)
        {
            //first column dfs
            if(board[i][0] == 'O' && !vis[i][0])
            {
                dfs(i, 0, board, vis);
            }  
            //last column dfs
            if(board[i][m-1] == 'O' && !vis[i][m-1])
            {
                dfs(i, m-1, board, vis);
            }
        }


        //all nodes/cells of matrix board which are not visited
        //which have value 'O' can be converted to 'X' as they are not connected to boundary items
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
