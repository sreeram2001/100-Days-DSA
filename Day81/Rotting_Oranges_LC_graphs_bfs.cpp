class Solution {
public:

    int orangesRotting(vector<vector<int>>& grid) {
        
        int time = 0;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0,1,0,-1};
        int n = grid.size();        //no. of rows
        int m= grid[0].size();      //no. of cols
        int max_time = 0;           //calculates overall time

        //this q stores, col, row and time taken for each iter.
        queue<pair<pair<int, int>, int>>q;

        //visited array which stores visit status of each cell
        int vis[n][m];

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 2)
                {
                    vis[i][j] = 2;
                    //push initial items to queue and vis array
                    q.push({{i,j}, 0});
                }
            }
        }

        //BFS
        while(!q.empty())
        {   
            //q = {{row, col}, time_taken}
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            q.pop();

            max_time = max(max_time, time);

            for(int i=0;i<=3;i++)
            {
                int nrow = drow[i] + row;
                int ncol = dcol[i] + col;
                if(nrow >= 0 && nrow <n && ncol >= 0 && ncol < m && vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1)
                {
                    q.push({{nrow, ncol}, time+1});
                    vis[nrow][ncol] = 2;
                }
            }
        }

        //now verify if all nodes are visited and turned to 2, if not its not possible
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j] != 2 && grid[i][j] == 1)
                {
                    return -1;
                }
            }
        }

        return max_time;

    }
};
