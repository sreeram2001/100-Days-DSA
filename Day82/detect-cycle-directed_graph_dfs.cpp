//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
    //helper function to detect cycle using dfs
    bool isDetect(int node, vector<int> adj[], int vis[], int pathVis[])
    {
        //mark as visited
        vis[node] = 1;
        pathVis[node] = 1;
        
        //now iterate or traverse thru adjacent nodes using dfs
        for(auto adjnode:adj[node])
        {   
            //if not visited then recursive dfs
            if(!vis[adjnode])
            {
                if(isDetect(adjnode, adj, vis, pathVis))
                {
                    return true;
                }
            }
            else
            {
                if(pathVis[adjnode])
                {
                    return true;
                }
            }
        }
        
        //re-initialize pathvis array to 0
        pathVis[node] = 0;
        return false;
    }
    
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int vis[V] = {0};
        int pathVis[V] = {0};
        
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(isDetect(i, adj, vis, pathVis))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends
