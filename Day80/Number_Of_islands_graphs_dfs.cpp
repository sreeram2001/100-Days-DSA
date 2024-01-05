class Solution {
public:

    void dfs(int row, int col, vector<vector<int>>& visit, vector<vector<char>> grid)
    {
        visit[row][col] = 1;
        int n = grid.size();    //row size
        int m = grid[0].size();  //col size

        //checking neighbours of the node

        //check top
        if( (row-1 >= 0 && col < m) && (!visit[row-1][col]) && grid[row-1][col] == '1')
        {
            dfs(row-1, col, visit, grid);
        }

        //check right
        if( (row < n  && col+1 < m) && !visit[row][col+1] && grid[row][col+1] == '1')
        {
            dfs(row, col+1, visit, grid);
        }

        //check bottom
        if( (row+1 < n && col < m) && !visit[row+1][col] && grid[row+1][col] == '1')
        {
            dfs(row+1, col, visit, grid);
        }

        //check left
        if( (row < n && col-1 >= 0) && !visit[row][col-1] && grid[row][col-1] == '1')
        {
            dfs(row, col-1, visit, grid);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;   //counts total islands
        vector<vector<int>> visit(n, vector<int>(m,0));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!visit[i][j] && grid[i][j] == '1')
                {   
                //if a cell is not covered in one dfs call, then separate call is made
                    //i.e. new island is formed there is no neighbor with val 1
                    count++;
                    dfs(i, j, visit, grid);
                }
            }
        }

        return count;

    }
};
