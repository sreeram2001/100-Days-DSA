//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        //output vector
        vector<int> op;
        //visited nodes array
        int visit[V] = {0};
        //initial node
        visit[0] = 1;
        //queue used for level order traversal - bfs
        queue<int> q;
        q.push(0);
        
        while(!q.empty())
        {
            //pop out the front element from queue
            int top = q.front();
            q.pop();
            op.push_back(top);
            
            //traverse thru each nodes adjacency list
            for(int i=0;i<adj[top].size();i++)
            {
                //if not present in visited array then visit the node
                if(visit[adj[top][i]] == 0)
                {   
                    visit[adj[top][i]] = 1;
                    //push the other connected nodes of current node to queue
                    q.push(adj[top][i]);
                }
            }
            
        }
        
         return op;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
