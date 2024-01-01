//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    
    void dfs(int node, vector<int> adj[], int visit[], vector<int> &op)
    {
        //mark the node as visited
        visit[node] = 1;
        //push it inside the output array
        op.push_back(node);
        
        //iterate thru the nodes adjacency list/connected nodes
        for(auto it:adj[node])
        {
            //if node is not visited yet then do dfs
            if(!visit[it])
            {
                dfs(it, adj, visit, op);
            }
        }
        
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        //output list
        vector<int> op;
        //array to capture visited nodes
        int visit[V] = {0};
        //starting node = 0
        int startnode = 0;
        
        dfs(startnode, adj, visit, op);
        return op;
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
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
