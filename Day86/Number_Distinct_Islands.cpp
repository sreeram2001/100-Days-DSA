//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<int>> grid,
    vector<pair<int, int>>& vect, int rowsrc, int colsrc)
    {   
        int n = grid.size();
        int m = grid[0].size();
        //mark as visited node
        vis[row][col] = 1;
        //push coordinates or indices into vect
        //current row index - source row index = row... similarily insert col index
        vect.push_back({row-rowsrc, col-colsrc});
        
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        
        for(int i=0;i<4;i++)
        {
            int nrow = delrow[i] + row;
            int ncol = delcol[i] + col;
            
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] 
            && grid[nrow][ncol] == 1)
            {
                dfs(nrow, ncol, vis, grid, vect, rowsrc, colsrc);
            }
        }
    }
  
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        //visited array
        vector<vector<int>> vis(n, vector<int>(m, 0));
        //set used to check unique islands wth help of indices
        set<vector<pair<int, int>>> unique;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j]==1)
                {
                    //vector used to store coordinates or index of land area 1's
                    vector<pair<int, int>> vect;
                    dfs(i, j, vis, grid, vect, i, j);
                    unique.insert(vect);
                }
            }
        }
        
        return unique.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends
