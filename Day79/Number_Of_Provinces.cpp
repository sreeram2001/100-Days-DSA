class Solution {
public:
    vector<vector<int>> op;

    void dfs(int node, vector<int> adj[], int vis[])
    {
        vis[node] = 1;

        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                dfs(it, adj, vis);
            }
        }

    }

    int findCircleNum(vector<vector<int>>& isConnected) {

        //setting up visited array
        int vis[isConnected.size()];
        for(int i=0;i<isConnected.size();i++)
        {
            vis[i] = 0;
        }

        // //converting matrix to adjacency list
        vector<int> adj[isConnected.size()];
        for(int i=0;i<isConnected.size();i++)
        {
            for(int j=0;j<isConnected.size();j++)
            {
                if(isConnected[i][j] == 1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int count = 0;  //output count

        //iterate from 1-V nodes and dfs
        for(int i=0;i<isConnected.size();i++)
        {
            //if not visited do dfs
            if(!vis[i])
            {
                count++;
                dfs(i, adj, vis);
            }
        }
        
        return count;
    }
};
