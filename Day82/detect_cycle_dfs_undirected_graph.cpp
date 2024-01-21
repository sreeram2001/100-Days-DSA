//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
    //HELPER FUNCTION TO DETECT CYCLING USING DFS
    bool detectDFS(int node, int parent, vector<int> adj[], int vis[])
    {
        //mark node as visited
        vis[node] = 1;
        
        //iterate thru adjacency nodes of the node, make recursive dfs calls
        for(auto adjnode:adj[node])
        {   
            //if its not visited yet, make dfs call
            if(!vis[adjnode])
            {
                if(detectDFS(adjnode, node, adj, vis))
                {
                    return true;
                }
            }
            else
            {
                //if already visited then check if adjacent node is same as parent node
                //if it is not parent node, then it didnt come thru that path, hence cycle
                if(adjnode != parent)
                {
                    return true;
                }
            }
        }
        
        return false;
    }
    
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        
        //node to mark visited nodes
        int vis[V] = {0};
        
        for(int i=0;i<V;i++)
        {
            if(!vis[i] && detectDFS(i, -1, adj, vis))
            {
                return true;
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends
