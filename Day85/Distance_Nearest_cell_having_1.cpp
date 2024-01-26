//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n = grid.size();
	    int m = grid[0].size();
	    
	    //visited array
	    vector<vector<int>> vis(n, vector<int>(m, 0));
	    //distance array
	    vector<vector<int>> dist(n, vector<int>(m,0));
	    //queue ds for bfs
	    queue<pair<pair<int, int>,int>> q;
	    
	    //initialize - for cells with 1's push inside q and marrk visited
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            if(grid[i][j] == 1)
	            {
	                vis[i][j] = 1;
	                q.push({{i,j},0});
	            }
	            else
	            {
	                vis[i][j] = 0;
	            }
	        }
	    }
	    
	    int delrow[] = {0,-1,0,1};
	    int delcol[] = {1,0,-1,0};
	    
	    //BFS ALGO
	    while(!q.empty())
	    {   
	        //get row and col indices
	        int row = q.front().first.first;
	        int col = q.front().first.second;
	        int distance = q.front().second;
	        q.pop();
	        dist[row][col] = distance;
	        
	        //for each node we can traverse in four directions
	        //left, right, up and down (r,c+1) (r-1,c) (r,c-1) (r+1,c)
	        //e.g. (0,1) (-1, 0) (0,-1) (1,0)
	        for(int i=0;i<4;i++)
	        {
	            int rrow = row + delrow[i];
	            int ccol = col + delcol[i];
	            
	            if(rrow >= 0 && rrow < n && ccol >=0 && ccol < m && vis[rrow][ccol] == 0)
	            {
	                vis[rrow][ccol] = 1;
	                q.push({{rrow,ccol}, distance+1});
	            }
	        }
	    }
	    
	    return dist;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends
