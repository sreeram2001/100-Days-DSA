//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    //bfs - helper function to detect cycle using bfs
    bool detect(int node, vector<int> adj[], int vis[])
    {
        vis[node] = 1;
        queue<pair<int, int>> q;
        //push initial node inside queue
        q.push({node, -1});
        
        while(!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            //iterate thru adjacent nodes of the current node
            for(auto adjnode:adj[node])
            {
                //if it is not in visited array mark it visited
                if(!vis[adjnode])
                {
                    vis[adjnode] = 1;
                    //push it inside the q ( bfs )
                    //push the node and its parent
                    q.push({adjnode, node});
                }
                else
                {
                    //if it is already visited and node is not same as parent,
                    //then it is a cycle
                    if(adjnode != parent)
                    {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
    
    
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        
        //safe to use a for loop for each in case component graph is input
        
        int vis[V] = {0};
        
        for(int i=0;i<V;i++)
        {
            //call detect function to check if any cycle is present in any node path
            if(!vis[i] && detect(i, adj, vis))
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
